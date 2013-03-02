/*
 * 
 *  Copyright 2013 Alan Race
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *
 */
#include "ImzMLFile.h"

#include "ImzMLHandler.h"

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

#include <boost/scoped_ptr.hpp>

#include <iostream>
#include <cmath>
#include "helpers/convert.h"

namespace ImzML {

	const std::string ImzMLFile::ns = "http://psi.hupo.org/ms/mzml";
	const std::string ImzMLFile::xsi = "http://www.w3.org/2001/XMLSchema-instance";
	const std::string ImzMLFile::schemaLocation = "http://psi.hupo.org/ms/mzml http://psidev.info/files/ms/mzML/xsd/mzML1.1.0_idx.xsd";
	const std::string ImzMLFile::currentVersion = "1.1.0";

	ImzMLFile::ImzMLFile(const char* filename) {
		init(filename, boost::shared_ptr<ImzML::OBO>());
	}

	ImzMLFile::ImzMLFile(const char* filename, boost::shared_ptr<ImzML::OBO> obo) {
		init(filename, obo);
	}

	void ImzMLFile::init(const char* filename, boost::shared_ptr<ImzML::OBO> obo) {
		width = 0;
		height = 0;
		depth = 0;

		parseimzML(filename, obo);
	}

	void ImzMLFile::parseimzML(const char* filename, boost::shared_ptr<ImzML::OBO> obo) {
		this->obo = obo;

		try {
			xercesc::XMLPlatformUtils::Initialize();
		} catch (const xercesc::XMLException& toCatch) {
			char* message = xercesc::XMLString::transcode(toCatch.getMessage());
			std::cout << "Error during initialization! :\n";
			std::cout << "Exception message is: \n"
				 << message << "\n";
			xercesc::XMLString::release(&message);
		}

		xercesc::SAX2XMLReader* parser = xercesc::XMLReaderFactory::createXMLReader();
		parser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
		parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);   // optional

		std::string imzMLFilename = std::string(filename);

		// Remove ".imzML" from the end of the file
		this->ibdLocation = imzMLFilename.substr(0, imzMLFilename.size()-6) + ".ibd";
		this->ibdStream.open(this->ibdLocation.c_str(), std::ios::in | std::ios::binary );

		boost::scoped_ptr<ImzML::ImzMLHandler> defaultHandler(new ImzML::ImzMLHandler(this, obo));
		parser->setContentHandler(defaultHandler.get());
		parser->setErrorHandler(defaultHandler.get());

		try {
			parser->parse(filename);
		} catch (const xercesc::XMLException& toCatch) {
			char* message = xercesc::XMLString::transcode(toCatch.getMessage());
			std::cout << "Exception message is: \n"
				 << message << "\n";
			xercesc::XMLString::release(&message);
		} catch (const xercesc::SAXParseException& toCatch) {
			char* message = xercesc::XMLString::transcode(toCatch.getMessage());
			std::cout << "Exception message is: \n"
				 << message << "\n";
			xercesc::XMLString::release(&message);
		} catch (...) {
			std::cout << "Unexpected Exception in ImzMLFile::parseimzML()\n" ;
		}

		delete parser;
	}


	ImzMLFile::~ImzMLFile() {
		this->ibdStream.close();
	}

	boost::shared_ptr<ImzML::Spectrum> ImzMLFile::getSpectrum(int x, int y) {
		return getSpectrum(x, y, 1);
	}

	boost::shared_ptr<ImzML::Spectrum> ImzMLFile::getSpectrum(int x, int y, int z) {
		int width = getWidth();
		int height = getHeight();
		int depth = getDepth();
		int imageSize = width * height;

		if(spectrumGrid.empty()) {
			//spectrumGrid = (ImzMLSpectrum****)malloc(sizeof(ImzMLSpectrum*) * getWidth() * getHeight() * getDepth());

			spectrumGrid.resize(imageSize*depth, boost::shared_ptr<ImzML::Spectrum>());

			int numSpectra = getRun()->getSpectrumList()->size();


			for(int i = 0; i < numSpectra; i++) {
				boost::shared_ptr<ImzML::Spectrum> spectrum = getRun()->getSpectrumList()->getSpectrum(i);

				int curX = spectrum->getX();
				int curY = spectrum->getY();
				int curZ = spectrum->getZ();

				// TODO: Checks
				spectrumGrid[((curZ-1)*imageSize) + ((curY-1)*width) + (curX-1)] = spectrum;
			}
		}


		if(x > 0 && x <= width && y > 0 && y <= height && z > 0 && z <= depth) {
			return spectrumGrid[((z-1)*imageSize) + ((y-1)*width) + (x-1)];
		}

		// TODO: Throw exception?

		return boost::shared_ptr<ImzML::Spectrum>();
	}

	std::vector<double> ImzMLFile::getBinnedmzList(double minMZ, double maxMZ, double binSize) {
		std::vector<double> mzs;

		// Round the min m/z down to the next lowest bin, and the max m/z up to the next bin
		minMZ = minMZ - fmod(minMZ, binSize);
		maxMZ = maxMZ + (binSize - fmod(maxMZ, binSize));
std::cout << minMZ << " - " << maxMZ << std::endl;
		int numBins = (int) ceil((maxMZ - minMZ) / binSize);

		mzs.reserve(numBins);

		for(int i = 0; i < numBins; i++)
			mzs.push_back(minMZ + (i * binSize));
		std::cout << mzs[0] << ", " << mzs[1] << ", "  << mzs[2] << " - " << mzs.size() << std::endl;
		return mzs;
	}

	boost::multi_array<double, 3> ImzMLFile::generateDatacube(double minMZ, double maxMZ, double binSize) {
		typedef boost::multi_array<double, 3> threeDArray;

		std::vector<double> mzs = getBinnedmzList(minMZ, maxMZ, binSize);

		int width = getWidth();
		int height = getHeight();
		int length = mzs.size();

		threeDArray dataCube(boost::extents[height][width][length]);

		for(threeDArray::index y = 0; y < height; y++) {
			for(threeDArray::index x = 0; x < width; x++) {
				for(threeDArray::index i = 0; i < length; i++) {
					dataCube[y][x][i] = 0;
				}

				boost::shared_ptr<ImzML::Spectrum> spectrum = getSpectrum(x, y);

				if(!spectrum)
					continue;

				std::vector<double> currentMZs = spectrum->getMZArray(ibdStream);
				std::vector<double> currentCounts = spectrum->getIntensityArray(ibdStream);

				int numMZs = currentMZs.size();

				for(int i = 0; i < numMZs; i++) {
					int index = (int)floor((currentMZs[i] - mzs[0]) / binSize);

//					std::cout << "m/z = " << currentMZs[i] << " (" << (currentMZs[i] - mzs[0]) << ") -> " << index << " - " << length <<  std::endl;

					if(index >= 0 && index < length) {
						dataCube[y][x][index] += currentCounts[i];
					}
				}
			}
		}

		return dataCube;
	}

	int ImzMLFile::getWidth() {
		if(width > 0)
			return width;

		// Check scan settings
		boost::shared_ptr<ImzML::ScanSettingsList> scanSettingsList = getScanSettingsList();

		if(scanSettingsList) {
			for(int i = 0; i < scanSettingsList->size(); i++) {
				boost::shared_ptr<ImzML::CVParam> maxCountPixelX = scanSettingsList->getScanSettings(i)->getMaxCountPixelX();

				if(maxCountPixelX) {
					width = convertToDouble(maxCountPixelX->getValue());
					break;
				}
			}
		}

		// TODO: If width not set then check all spectra for largest width

		return width;
	}

	int ImzMLFile::getHeight() {
		if(height > 0)
			return height;

		boost::shared_ptr<ImzML::ScanSettingsList> scanSettingsList = getScanSettingsList();

		if(scanSettingsList != NULL) {
			for(int i = 0; i < scanSettingsList->size(); i++) {
				boost::shared_ptr<ImzML::CVParam> maxCountPixelY = scanSettingsList->getScanSettings(i)->getMaxCountPixelY();

				if(maxCountPixelY != NULL) {
					height = convertToDouble(maxCountPixelY->getValue());
					break;
				}
			}
		}

		// TODO: If height not set then check all spectra for largest height

		return height;
	}

	int ImzMLFile::getDepth() {
		if(depth > 0)
			return depth;

		// TODO: 3D handling

		depth = 1;

		return depth;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::ImzMLFile& imzML) {
		os << "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>" << std::endl;
		os << "<mzML xmlns:xsi=\"" << ImzMLFile::xsi << "\" xsi:schemaLocation=\"" << ImzMLFile::schemaLocation << "\" xmlns=\"" << ImzMLFile::ns << "\" version=\"" << ImzMLFile::currentVersion << "\" >" << std::endl;

		MzMLContent::indent++;

		if(imzML.cvList != NULL)
			os << *imzML.cvList << std::endl;
		if(imzML.fileDescription != NULL)
			os << *imzML.fileDescription << std::endl;
		if(imzML.referenceableParamGroupList != NULL)
			os << *imzML.referenceableParamGroupList << std::endl;
		if(imzML.sampleList != NULL)
			os << *imzML.sampleList << std::endl;
		if(imzML.softwareList != NULL)
			os << *imzML.softwareList << std::endl;
		if(imzML.scanSettingsList != NULL)
			os << *imzML.scanSettingsList << std::endl;
		if(imzML.instrumentConfigurationList != NULL)
			os << *imzML.instrumentConfigurationList << std::endl;
		if(imzML.dataProcessingList != NULL)
			os << *imzML.dataProcessingList << std::endl;
		if(imzML.run != NULL)
			os << *imzML.run << std::endl;

		MzMLContent::indent--;

		os << "</mzML>" << std::endl;

		return os;
	}

} /* namespace ImzML */
