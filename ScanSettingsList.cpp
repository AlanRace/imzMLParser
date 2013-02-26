/*
 * ScanSettingsList.cpp
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#include "ScanSettingsList.h"

namespace ImzML {

	ScanSettingsList::ScanSettingsList(int count) {
	}

	ScanSettingsList::~ScanSettingsList()
	{
		// TODO Auto-generated destructor stub
	}

	void ScanSettingsList::addScanSettings(boost::shared_ptr<ImzML::ScanSettings> scanSettings) {
		scanSettingsList.push_back(scanSettings);
	}

	boost::shared_ptr<ImzML::ScanSettings> ScanSettingsList::getScanSettings(int index) {
		return scanSettingsList[index];
	}

	boost::shared_ptr<ImzML::ScanSettings> ScanSettingsList::getScanSettings(std::string id) {
		for(std::vector< boost::shared_ptr<ImzML::ScanSettings> >::iterator iter = scanSettingsList.begin(); iter < scanSettingsList.end(); iter++)
			if(id.compare((*iter)->getID()) == 0)
				return *iter;

		return boost::shared_ptr<ImzML::ScanSettings>();
	}

	int ScanSettingsList::size() {
		return scanSettingsList.size();
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::ScanSettingsList& scanSettingsList) {
		for(int i = 0; i < scanSettingsList.indent; i++)
			os << scanSettingsList.indentString;
		os << "<scanSettingsList count=\"" << scanSettingsList.scanSettingsList.size() << "\">" << std::endl;

		scanSettingsList.indent++;
		for(int i = 0; i < scanSettingsList.scanSettingsList.size(); i++)
			os << *scanSettingsList.scanSettingsList[i] << std::endl;
		scanSettingsList.indent--;

		for(int i = 0; i < scanSettingsList.indent; i++)
			os << scanSettingsList.indentString;
		os << "</scanSettingsList>";

		return os;
	}

} /* namespace ImzML */

