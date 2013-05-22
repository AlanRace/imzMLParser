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
/*
 * ImzMLSpectrum.cpp
 *
 *  Created on: 18 May 2012
 *      Author: Alan Race
 */

#include "Spectrum.h"
#include "helpers/convert.h"


namespace ImzML {

	Spectrum::Spectrum() {

	}

	Spectrum::Spectrum(const ImzML::Spectrum& spectrum) :
		ImzML::MzMLContent(spectrum) {
		if(spectrum.binaryDataArrayList)
			binaryDataArrayList = spectrum.binaryDataArrayList;
		else
			binaryDataArrayList.reset();

		if(spectrum.dataProcessing)
			dataProcessing = spectrum.dataProcessing;
		else
			dataProcessing.reset();

		if(spectrum.scanList)
			scanList = spectrum.scanList;
		else
			scanList.reset();

		id = spectrum.id;
		defaultArrayLength = spectrum.defaultArrayLength;
		index = spectrum.index;

		ibdStream = spectrum.ibdStream;
		ibdLocation = spectrum.ibdLocation;
	}

	Spectrum::Spectrum(std::string id, int defaultArrayLength, int index) :
			id(id),
			defaultArrayLength(defaultArrayLength),
			index(index) {

	}

	Spectrum::~Spectrum()
	{
	}

	boost::shared_ptr<ImzML::BinaryDataArrayList> Spectrum::getBinaryDataArrayList() {
		// TODO: Check that this happens using both converters - omitting binaryDataArray
		//		 from some pixels when using AB MS Data Converter
		if(!binaryDataArrayList)
			binaryDataArrayList.reset(new BinaryDataArrayList(0));

		return binaryDataArrayList;
	}

	int Spectrum::getX() {

		for(int i = 0; i < scanList->size(); i++) {
			boost::shared_ptr<ImzML::CVParam> xPos = scanList->getScan(i)->getCVParam(ImzML::Accession::positionXID);

			if(xPos)
				return convertToDouble(xPos->getValue());
		}

		// TODO: exception?

		return 1;
	}

	int Spectrum::getY() {
		for(int i = 0; i < scanList->size(); i++) {
			boost::shared_ptr<ImzML::CVParam> yPos = scanList->getScan(i)->getCVParam(ImzML::Accession::positionYID);

			if(yPos)
				return convertToDouble(yPos->getValue());
		}

		// TODO: exception?

		return 1;
	}

	int Spectrum::getZ() {
		for(int i = 0; i < scanList->size(); i++) {
			boost::shared_ptr<ImzML::CVParam> zPos = scanList->getScan(i)->getCVParam(ImzML::Accession::positionZID);

			if(zPos)
				return convertToDouble(zPos->getValue());
		}

		// TODO: exception?

		// If no z position is specified, assume that it is in position 1
		return 1;
	}

	/*ImzML::BinaryDataArray* */
	std::vector<double> Spectrum::getMZArray() {
		return getMZArray(*this->ibdStream);
	}

	std::vector<double> Spectrum::getMZArray(std::ifstream &ibd) {
		if(!binaryDataArrayList || !binaryDataArrayList->getMZArray())
			throw "BinaryDataArrayList (m/z) missing";

		boost::shared_ptr<BinaryDataArray> mzArray = binaryDataArrayList->getMZArray();

		return mzArray->getDouble(ibd);
	}

	/*ImzML::BinaryDataArray* */
	std::vector<double> Spectrum::getIntensityArray() {
		return getIntensityArray(*this->ibdStream);
	}

	std::vector<double> Spectrum::getIntensityArray(std::ifstream &ibd) {
		if(!binaryDataArrayList || !binaryDataArrayList->getIntensityArray())
			throw "BinaryDataArrayList missing";

		boost::shared_ptr<BinaryDataArray> intensityArray = binaryDataArrayList->getIntensityArray();

		return intensityArray->getDouble(ibd);
	}

    void Spectrum::getIntensityArray(std::ifstream &ibd, double* dataLocation) {
		if(!binaryDataArrayList || !binaryDataArrayList->getIntensityArray())
			throw "BinaryDataArrayList missing";

		binaryDataArrayList->getIntensityArray()->getDouble(ibd, dataLocation);
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::Spectrum& spectrum) {
		for(int i = 0; i < spectrum.indent; i++)
			os << spectrum.indentString;
		os << "<spectrum defaultArrayLength=\"" << spectrum.defaultArrayLength << "\" id=\"" << spectrum.id << "\">" << std::endl;

		spectrum.indent++;
		os << (ImzML::MzMLContent&)(spectrum);

		if(spectrum.scanList != NULL)
			os << *spectrum.scanList << std::endl;

		if(spectrum.binaryDataArrayList != NULL)
			os << *spectrum.binaryDataArrayList << std::endl;

		spectrum.indent--;

		for(int i = 0; i < spectrum.indent; i++)
			os << spectrum.indentString;
		os << "</spectrum>";

		return os;
	}

} /* namespace ImzML */


