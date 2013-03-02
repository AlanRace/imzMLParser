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
#ifndef IMZMLHANDLER_H
#define IMZMLHANDLER_H

#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/Attributes.hpp>

#include "ImzMLFile.h"
#include "CVList.h"
#include "FileDescription.h"
#include "SourceFileList.h"
#include "ReferenceableParamGroupList.h"
#include "SampleList.h"
#include "SoftwareList.h"
#include "ScanSettingsList.h"
#include "ScanSettings.h"
#include "SourceFileRefList.h"
#include "TargetList.h"
#include "InstrumentConfigurationList.h"
#include "InstrumentConfiguration.h"
#include "ComponentList.h"
#include "DataProcessingList.h"
#include "DataProcessing.h"
#include "Run.h"
#include "SpectrumList.h"
#include "Spectrum.h"
#include "ScanList.h"
#include "Scan.h"
#include "ScanWindowList.h"
#include "PrecursorList.h"
#include "Precursor.h"
#include "SelectedIonList.h"
#include "ProductList.h"
#include "Product.h"
#include "BinaryDataArrayList.h"
#include "BinaryDataArray.h"
#include "ChromatogramList.h"
#include "Chromatogram.h"

namespace ImzML {

	class ImzMLHandler : public xercesc::DefaultHandler
	{
		protected:
			boost::shared_ptr<ImzML::OBO> obo;

			ImzML::ImzMLFile* currentimzML;
	
			boost::shared_ptr<ImzML::CVList> cvList;
			boost::shared_ptr<ImzML::FileDescription> fileDescription;
			boost::shared_ptr<ImzML::SourceFileList> 					sourceFileList;
			boost::shared_ptr<ImzML::ReferenceableParamGroupList> 	referenceableParamGroupList;
			boost::shared_ptr<ImzML::SampleList> 						sampleList;
			boost::shared_ptr<ImzML::SoftwareList> 					softwareList;
			boost::shared_ptr<ImzML::ScanSettingsList> 				scanSettingsList;
			boost::shared_ptr<ImzML::ScanSettings>					currentScanSettings;
			boost::shared_ptr<ImzML::SourceFileRefList> 				currentSourceFileRefList;
			boost::shared_ptr<ImzML::TargetList> currentTargetList;
			boost::shared_ptr<ImzML::InstrumentConfigurationList> instrumentConfigurationList;
			boost::shared_ptr<ImzML::InstrumentConfiguration> currentInstrumentConfiguration;
			boost::shared_ptr<ImzML::ComponentList> currentComponentList;
			boost::shared_ptr<ImzML::DataProcessingList> dataProcessingList;
			boost::shared_ptr<ImzML::DataProcessing> currentDataProcessing;
			boost::shared_ptr<ImzML::Run> run;
			boost::shared_ptr<ImzML::SpectrumList> spectrumList;
			boost::shared_ptr<ImzML::Spectrum> currentSpectrum;
			boost::shared_ptr<ImzML::ScanList> currentScanList;
			boost::shared_ptr<ImzML::Scan> currentScan;
			boost::shared_ptr<ImzML::ScanWindowList> currentScanWindowList;
			boost::shared_ptr<ImzML::PrecursorList> currentPrecursorList;
			boost::shared_ptr<ImzML::Precursor> currentPrecursor;
			boost::shared_ptr<ImzML::SelectedIonList> currentSelectedIonList;
			boost::shared_ptr<ImzML::ProductList> currentProductList;
			boost::shared_ptr<ImzML::Product> currentProduct;
			boost::shared_ptr<ImzML::BinaryDataArrayList> currentBinaryDataArrayList;
			boost::shared_ptr<ImzML::BinaryDataArray> currentBinaryDataArray;
			boost::shared_ptr<ImzML::ChromatogramList> chromatogramList;
			boost::shared_ptr<ImzML::Chromatogram> currentChromatogram;
		
			boost::shared_ptr<ImzML::MzMLContent> currentContent;
			boost::shared_ptr<ImzML::FileDescription> currentFD;
			boost::shared_ptr<ImzML::InstrumentConfiguration> currentIC;
			boost::shared_ptr<ImzML::DataProcessing> currentDP;

			bool processingSpectrum;
			bool processingChromatogram;

			bool processingPrecursor;
			bool processingProduct;

			XMLCh* ns;

		public:

			ImzMLHandler(ImzML::ImzMLFile* currentimzML, boost::shared_ptr<OBO> obo) : DefaultHandler() {
				this->obo = obo;
				this->ns = xercesc::XMLString::transcode("");
				this->currentimzML = currentimzML;
			}

			void startElement(
				const   XMLCh* const    uri,
				const   XMLCh* const    localname,
				const   XMLCh* const    qname,
				const   xercesc::Attributes&     attrs
			);

			//void fatalError(const xercesc::SAXParseException&);
	};

} /* namespace ImzML */

#endif // IMZMLHANDLER_H
