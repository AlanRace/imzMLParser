#ifndef IMZMLFILE_H
#define IMZMLFILE_H

#include <vector>
#include <string>

//#include <xercesc/util/PlatformUtils.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/multi_array.hpp>

#include "OBO.h"

#include "CVList.h"
#include "FileDescription.h"
#include "ReferenceableParamGroupList.h"
#include "SampleList.h"
#include "SoftwareList.h"
#include "ScanSettingsList.h"
#include "InstrumentConfigurationList.h"
#include "DataProcessingList.h"
#include "Run.h"

namespace ImzML {

	class ImzMLFile
	{
		// TODO: accession
		// TODO: id
		protected:
			boost::shared_ptr<ImzML::OBO> obo;

			std::string version;

			boost::shared_ptr<ImzML::CVList> cvList;
			boost::shared_ptr<ImzML::FileDescription> fileDescription;
			boost::shared_ptr<ImzML::ReferenceableParamGroupList> referenceableParamGroupList;
			boost::shared_ptr<ImzML::SampleList> sampleList;
			boost::shared_ptr<ImzML::SoftwareList> softwareList;
			boost::shared_ptr<ImzML::ScanSettingsList> scanSettingsList;
			boost::shared_ptr<ImzML::InstrumentConfigurationList> instrumentConfigurationList;
			boost::shared_ptr<ImzML::DataProcessingList> dataProcessingList;
			boost::shared_ptr<ImzML::Run> run;

			//
			int width;
			int height;
			int depth;

			std::vector< boost::shared_ptr<ImzML::Spectrum> > spectrumGrid;

			std::string ibdLocation;
			std::ifstream ibdStream;

		public:
			static const std::string ns;
			static const std::string xsi;
			static const std::string schemaLocation;

			static const std::string currentVersion;

			ImzMLFile(const char* filename, boost::shared_ptr<ImzML::OBO> obo);
			ImzMLFile(const char* filename);
			~ImzMLFile();

			void init(const char* filename, boost::shared_ptr<ImzML::OBO> obo);

			void parseimzML(const char* filename, boost::shared_ptr<ImzML::OBO> obo);

			void setVersion(std::string verison) { this->version = version; }
			void setCVList(boost::shared_ptr<ImzML::CVList> cvList) { this->cvList = cvList; }
			void setFileDescription(boost::shared_ptr<ImzML::FileDescription> fileDescription) { this->fileDescription = fileDescription; }
			void setReferenceableParamGroupList(boost::shared_ptr<ImzML::ReferenceableParamGroupList> referenceableParamGroupList) { this->referenceableParamGroupList = referenceableParamGroupList; }
			void setSampleList(boost::shared_ptr<ImzML::SampleList> sampleList) { this->sampleList = sampleList; }
			void setSoftwareList(boost::shared_ptr<ImzML::SoftwareList> softwareList) { this->softwareList = softwareList; }
			void setScanSettingsList(boost::shared_ptr<ImzML::ScanSettingsList> scanSettingsList) { this->scanSettingsList = scanSettingsList; }
			void setInstrumentConfigurationList(boost::shared_ptr<ImzML::InstrumentConfigurationList> instrumentConfigurationList) { this->instrumentConfigurationList = instrumentConfigurationList; }
			void setDataProcessingList(boost::shared_ptr<ImzML::DataProcessingList> dataProcessingList) { this->dataProcessingList = dataProcessingList; }
			void setRun(boost::shared_ptr<ImzML::Run> run) { this->run = run; }

			std::string getVersion() { return version; }
			boost::shared_ptr<ImzML::CVList> getCVList() { return cvList; }
			boost::shared_ptr<ImzML::FileDescription> getFileDescription() { return fileDescription; }
			boost::shared_ptr<ImzML::ReferenceableParamGroupList> getReferenceableParamGroupList() { return referenceableParamGroupList; }
			boost::shared_ptr<ImzML::SampleList> getSampleList() { return sampleList; }
			boost::shared_ptr<ImzML::SoftwareList> getSoftwareList() { return softwareList; }
			boost::shared_ptr<ImzML::ScanSettingsList> getScanSettingsList() { return scanSettingsList; }
			boost::shared_ptr<ImzML::InstrumentConfigurationList> getInstrumentConfigurationList() { return instrumentConfigurationList; }
			boost::shared_ptr<ImzML::DataProcessingList> getDataProcessingList() { return dataProcessingList; }
			boost::shared_ptr<ImzML::Run> getRun() { return run; }

			// Get spectra helper methods
			boost::shared_ptr<ImzML::Spectrum> getSpectrum(int x, int y);
			boost::shared_ptr<ImzML::Spectrum> getSpectrum(int x, int y, int z);

			std::vector<double> getBinnedmzList(double minMZ, double maxMZ, double binSize);
			boost::multi_array<double, 3> generateDatacube(double minMZ, double maxMZ, double binSize);

			// Get image properties
			int getWidth();
			int getHeight();
			int getDepth();

			std::string getibdLocation() { return ibdLocation; }
			std::ifstream* getibdStream() { return &ibdStream; }

			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::ImzMLFile& imzML);
	};
	
} /* namespace ImzML */

#endif // IMZMLFILE_H
