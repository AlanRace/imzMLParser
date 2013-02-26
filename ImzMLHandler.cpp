#include "ImzMLHandler.h"
#include "CVParam.h"

#include <iostream>

#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax/SAXParseException.hpp>
#include <xercesc/sax/SAXException.hpp>

#include <boost/shared_ptr.hpp>

#define GetAttribute(x) ((xercesc::XMLString::transcode(attrs.getValue(ns, xercesc::XMLString::transcode(x)))) ? (xercesc::XMLString::transcode(attrs.getValue(ns, xercesc::XMLString::transcode(x)))) : "") //((attrs.getValue(ns, xercesc::XMLString::transcode(x)) != NULL)? xercesc::XMLString::transcode(attrs.getValue(ns, xercesc::XMLString::transcode(x))) : NULL)

namespace ImzML {

	void ImzMLHandler::startElement(const   XMLCh* const    uri,
				const   XMLCh* const    localname,
				const   XMLCh* const    qname,
				const   xercesc::Attributes&     attrs) {

		char* message = xercesc::XMLString::transcode(localname);

		if(strcmp(message, "cvParam") == 0) {
			boost::shared_ptr<ImzML::CVParam> cvParam;

			const char* unitAccession = GetAttribute("unitAccession");

			if(unitAccession != NULL) {
				if(obo == NULL)
					cvParam.reset(new ImzML::CVParam(GetAttribute("accession"), GetAttribute("name"), GetAttribute("value"), GetAttribute("unitAccession"), GetAttribute("unitName")));
				else
					cvParam.reset(new ImzML::CVParam(obo->getTerm(GetAttribute("accession")), GetAttribute("value"), obo->getTerm(GetAttribute("unitAccession"))));
			} else {
				if(obo == NULL)
					cvParam.reset(new ImzML::CVParam(GetAttribute("accession"), GetAttribute("name"), GetAttribute("value")));
				else
					cvParam.reset(new ImzML::CVParam(obo->getTerm(GetAttribute("accession")), GetAttribute("value")));
			}

			if(currentContent)
				currentContent->addCvParam(cvParam);
		} else if(strcmp(message, "referenceableParamGroupRef") == 0) {
			boost::shared_ptr<ImzML::ReferenceableParamGroup> rpg(referenceableParamGroupList->getReferenceableParamGroup(GetAttribute("ref")));

			if(currentContent)
				currentContent->addReferenceableParamGroup(rpg);
		} else if(strcmp(message, "cvList") == 0) {
			cvList.reset(new ImzML::CVList(strtol(GetAttribute("count"), NULL, 10)));

			currentimzML->setCVList(cvList);
		} else if(strcmp(message, "cv") == 0) {
			if(cvList)
				cvList->addCV(new ImzML::CV(GetAttribute("uri"), GetAttribute("fullName"), GetAttribute("id"), GetAttribute("version")));
		} else if(strcmp(message, "fileDescription") == 0) {
			fileDescription.reset(new ImzML::FileDescription());

			currentimzML->setFileDescription(fileDescription);
		} else if(strcmp(message, "fileContent") == 0) {
			boost::shared_ptr<ImzML::FileContent> fileContent(new ImzML::FileContent());

			fileDescription->setFileContent(fileContent);
			currentContent = fileContent;
		} else if(strcmp(message, "sourceFileList") == 0) {
			sourceFileList.reset(new ImzML::SourceFileList(strtol(GetAttribute("count"), NULL, 10)));

			fileDescription->setSourceFileList(sourceFileList);
		} else if(strcmp(message, "sourceFile") == 0) {
			boost::shared_ptr<ImzML::SourceFile> sourceFile(new ImzML::SourceFile(GetAttribute("id"), GetAttribute("location"), GetAttribute("name")));

			if(sourceFileList)
				sourceFileList->addSourceFile(sourceFile);

			currentContent = sourceFile;
		} else if(strcmp(message, "referenceableParamGroupList") == 0) {
			referenceableParamGroupList.reset(new ImzML::ReferenceableParamGroupList(strtol(GetAttribute("count"), NULL, 10)));

			currentimzML->setReferenceableParamGroupList(referenceableParamGroupList);
		} else if(strcmp(message, "referenceableParamGroup") == 0) {
			boost::shared_ptr<ImzML::ReferenceableParamGroup> rpg(new ImzML::ReferenceableParamGroup(GetAttribute("id")));

			currentContent = rpg;
			referenceableParamGroupList->addReferenceableParamGroup(rpg);
		} else if(strcmp(message, "softwareList") == 0) {
			softwareList.reset(new ImzML::SoftwareList(strtol(GetAttribute("count"), NULL, 10)));

			currentimzML->setSoftwareList(softwareList);
		} else if(strcmp(message, "software") == 0) {
			boost::shared_ptr<ImzML::Software> software(new Software(GetAttribute("id"), GetAttribute("version")));

			softwareList->addSoftware(software);
			currentContent = software;
		} else if(strcmp(message, "scanSettingsList") == 0) {
			scanSettingsList.reset(new ImzML::ScanSettingsList(strtol(GetAttribute("count"), NULL, 10)));

			currentimzML->setScanSettingsList(scanSettingsList);
		} else if(strcmp(message, "scanSettings") == 0) {
			currentScanSettings.reset(new ImzML::ScanSettings(GetAttribute("id")));

			scanSettingsList->addScanSettings(currentScanSettings);
			currentContent = currentScanSettings;
		} else if(strcmp(message, "instrumentConfigurationList") == 0) {
			instrumentConfigurationList.reset(new ImzML::InstrumentConfigurationList(strtol(GetAttribute("count"), NULL, 10)));

			currentimzML->setInstrumentConfigurationList(instrumentConfigurationList);
		} else if(strcmp(message, "instrumentConfiguration") == 0) {
			currentInstrumentConfiguration.reset(new ImzML::InstrumentConfiguration(GetAttribute("id")));

			// TODO: ScanSettings

			instrumentConfigurationList->addInstrumentConfiguration(currentInstrumentConfiguration);
			currentContent = currentInstrumentConfiguration;
		} else if(strcmp(message, "componentList") == 0) {
			currentComponentList.reset(new ImzML::ComponentList(strtol(GetAttribute("count"), NULL, 10)));

			if(currentInstrumentConfiguration)
				currentInstrumentConfiguration->setComponentList(currentComponentList);
		} else if(strcmp(message, "source") == 0) {
			boost::shared_ptr<ImzML::Source> source(new ImzML::Source(strtol(GetAttribute("order"), NULL, 10)));

			if(currentComponentList)
				currentComponentList->addSource(source);

			currentContent = source;
		} else if(strcmp(message, "analyzer") == 0) {
			boost::shared_ptr<ImzML::Analyser> analyser(new ImzML::Analyser(strtol(GetAttribute("order"), NULL, 10)));

			if(currentComponentList)
				currentComponentList->addAnalyser(analyser);

			currentContent = analyser;
		} else if(strcmp(message, "detector") == 0) {
			boost::shared_ptr<ImzML::Detector> detector(new ImzML::Detector(strtol(GetAttribute("order"), NULL, 10)));

			if(currentComponentList != NULL)
				currentComponentList->addDetector(detector);

			currentContent = detector;
		} else if(strcmp(message, "softwareRef") == 0) {
			// TODO: Add in better reporting on errors
			if(softwareList) {
				boost::shared_ptr<ImzML::Software> software(softwareList->getSoftware(GetAttribute("ref")));

				if(software && currentInstrumentConfiguration)
					currentInstrumentConfiguration->setSoftwareRef(software);
			}
		} else if(strcmp(message, "dataProcessingList") == 0) {
			dataProcessingList.reset(new ImzML::DataProcessingList(strtol(GetAttribute("count"), NULL, 10)));

			currentimzML->setDataProcessingList(dataProcessingList);
		} else if(strcmp(message, "dataProcessing") == 0) {
			boost::shared_ptr<ImzML::DataProcessing> dp(new ImzML::DataProcessing(GetAttribute("id")));

			dataProcessingList->addDataProcessing(dp);
			currentDataProcessing = dp;
			currentContent = dp;
		} else if(strcmp(message, "processingMethod") == 0) {
			// TODO: Add in better error reporting
			boost::shared_ptr<ImzML::Software> softwareRef(softwareList->getSoftware(GetAttribute("softwareRef")));

			if(softwareRef && currentDataProcessing) {
				boost::shared_ptr<ImzML::ProcessingMethod> processingMethod(new ImzML::ProcessingMethod(strtol(GetAttribute("order"), NULL, 10), softwareRef));

				currentDataProcessing->addProcessingMethod(processingMethod);
				currentContent = processingMethod;
			} else {
				currentContent = boost::shared_ptr<ImzML::MzMLContent>();
			}
		} else if(strcmp(message, "run") == 0) {
			const char* id =  GetAttribute("id");
			const char* defaultInstrumentConfigurationRef = GetAttribute("defaultInstrumentConfigurationRef");

			run.reset(new ImzML::Run(id, instrumentConfigurationList->getInstrumentConfiguration(defaultInstrumentConfigurationRef)));

			// TODO: defaultSourceFileRef
			// TODO: sampleRef
			// TODO: startTimeStamp

			currentimzML->setRun(run);
			currentContent = run;
		} else if(strcmp(message, "spectrumList") == 0) {
			std::string defaultDataProcessingRef(GetAttribute("defaultDataProcessingRef"));

			if(defaultDataProcessingRef.size() != 0)
				spectrumList.reset(new ImzML::SpectrumList(strtol(GetAttribute("count"), NULL, 10), dataProcessingList->getDataProcessing(defaultDataProcessingRef)));
			else
				spectrumList.reset(new ImzML::SpectrumList(strtol(GetAttribute("count"), NULL, 10), boost::shared_ptr<ImzML::DataProcessing>()));

			run->setSpectrumList(spectrumList);
		} else if(strcmp(message, "spectrum") == 0) {
			currentSpectrum.reset(new ImzML::Spectrum(GetAttribute("id"), strtol(GetAttribute("defaultArrayLength"), NULL, 10), strtol(GetAttribute("index"), NULL, 10)));

			// TODO: dataProcessingRef
			// TODO: sourceFileRef
			// TODO: spotID

			currentSpectrum->setibdLocation(currentimzML->getibdLocation(), currentimzML->getibdStream());

			processingSpectrum = true;
			spectrumList->addSpectrum(currentSpectrum);
			currentContent = currentSpectrum;
		} else if(strcmp(message, "scanList") == 0) {
			currentScanList.reset(new ImzML::ScanList(strtol(GetAttribute("count"), NULL, 10)));

			currentSpectrum->setScanList(currentScanList);
			currentContent = currentScanList;
		} else if(strcmp(message, "scan") == 0) {
			currentScan.reset(new ImzML::Scan());

			// TODO: externalSpectrumID
			// TODO: instrumentConfigurationRef
			// TODO: sourceFileRef
			// TODO: spectrumRef

			currentScanList->addScan(currentScan);
			currentContent = currentScan;
		} else if(strcmp(message, "scanWindowList") == 0) {
			currentScanWindowList.reset(new ImzML::ScanWindowList(strtol(GetAttribute("count"), NULL, 10)));

			currentScan->setScanWindowList(currentScanWindowList);
		} else if(strcmp(message, "scanWindow") == 0) {
			boost::shared_ptr<ImzML::ScanWindow> scanWindow(new ImzML::ScanWindow());

			currentScanWindowList->addScanWindow(scanWindow);
			currentContent = scanWindow;
		} else if(strcmp(message, "binaryDataArrayList") == 0) {
			currentBinaryDataArrayList.reset(new ImzML::BinaryDataArrayList(strtol(GetAttribute("count"), NULL, 10)));

			if(processingSpectrum)
				currentSpectrum->setBinaryDataArrayList(currentBinaryDataArrayList);
	//		else if(processingChromatogram)
	//			currentChromatogram->setBinaryDataArrayList(currentBinaryDataArrayList);
		} else if(strcmp(message, "binaryDataArray") == 0) {
			currentBinaryDataArray.reset(new ImzML::BinaryDataArray(strtol(GetAttribute("encodedLength"), NULL, 10)));

			// TODO: arrayLength
			// TODO: dataProcessingRef
			currentBinaryDataArrayList->addBinaryDataArray(currentBinaryDataArray);
			currentContent = currentBinaryDataArray;
		} else if(strcmp(message, "binary") == 0) {
		}

		xercesc::XMLString::release(&message);
	}

} /* namespace ImzML */
