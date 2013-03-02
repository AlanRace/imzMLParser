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
 * ScanSettingsList.cpp
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#include "ScanSettingsList.h"

namespace ImzML {

	ScanSettingsList::ScanSettingsList(int count) {
        scanSettingsList.reserve(count);
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
        for(ImzML::ScanSettingsList::scanSettingsList_type::size_type i = 0; i < scanSettingsList.scanSettingsList.size(); i++)
			os << *scanSettingsList.scanSettingsList[i] << std::endl;
		scanSettingsList.indent--;

		for(int i = 0; i < scanSettingsList.indent; i++)
			os << scanSettingsList.indentString;
		os << "</scanSettingsList>";

		return os;
	}

} /* namespace ImzML */

