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
 * DataProcessingList.cpp
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#include "DataProcessingList.h"

namespace ImzML {

	DataProcessingList::DataProcessingList(int count) {
		dataProcessingList.reserve(count);
	}

	DataProcessingList::~DataProcessingList()
	{
		// TODO Auto-generated destructor stub
	}

	void DataProcessingList::addDataProcessing(boost::shared_ptr<ImzML::DataProcessing> dataProcessing) {
		dataProcessingList.push_back(dataProcessing);
	}

	boost::shared_ptr<ImzML::DataProcessing> DataProcessingList::getDataProcessing(int index) {
		return dataProcessingList[index];
	}

	boost::shared_ptr<ImzML::DataProcessing> DataProcessingList::getDataProcessing(std::string id) {
		for(std::vector< boost::shared_ptr<ImzML::DataProcessing> >::iterator iter = dataProcessingList.begin(); iter < dataProcessingList.end(); iter++)
			if(id.compare((*iter)->getID()) == 0)
				return *iter;

		return boost::shared_ptr<ImzML::DataProcessing>();
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::DataProcessingList& dpl) {
		for(int i = 0; i < dpl.indent; i++)
			os << dpl.indentString;
		os << "<dataProcessingList count=\"" << dpl.dataProcessingList.size() << "\">" << std::endl;

		dpl.indent++;
        for(ImzML::DataProcessingList::dataProcessingList_type::size_type i = 0; i < dpl.dataProcessingList.size(); i++)
			os << *dpl.dataProcessingList[i] << std::endl;
		dpl.indent--;

		for(int i = 0; i < dpl.indent; i++)
			os << dpl.indentString;
		os << "</dataProcessingList>";

		return os;
	}

} /* namespace ImzML */

