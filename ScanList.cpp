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
#include "ScanList.h"

namespace ImzML {

	ScanList::~ScanList() {
	}

	void ScanList::addScan(boost::shared_ptr<ImzML::Scan> scan) {
		scanList.push_back(scan);
	}

	boost::shared_ptr<ImzML::Scan> ScanList::getScan(int index) {
		return scanList[index];
	}

	int ScanList::size() {
		return scanList.size();
	}


	std::ostream& operator<<(std::ostream& os, const ImzML::ScanList& scanList) {
		for(int i = 0; i < scanList.indent; i++)
			os << scanList.indentString;
		os << "<scanList count=\"" << scanList.scanList.size() << "\">" << std::endl;

		scanList.indent++;
		os << (ImzML::MzMLContent&) scanList;

        for(ImzML::ScanList::scanList_type::size_type i = 0; i < scanList.scanList.size(); i++)
			os << *scanList.scanList[i] << std::endl;

		scanList.indent--;

		for(int i = 0; i < scanList.indent; i++)
			os << scanList.indentString;
		os << "</scanList>";

		return os;
	}

} /* namespace ImzML */
