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
 * CVList.cpp
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#include "CVList.h"

#include <iostream>

namespace ImzML {

	CVList::CVList(int count)
	{
		cvList.reserve(count);

	}

	CVList::~CVList()
	{
		// TODO Auto-generated destructor stub
	}

	void CVList::addCV(ImzML::CV* cv) {
		cvList.push_back(cv);
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::CVList& cvList) {
		for(int i = 0; i < cvList.indent; i++)
			os << cvList.indentString;
		os << "<cvList count=\"" << cvList.cvList.size() << "\">" << std::endl;

		cvList.indent++;
        for(ImzML::CVList::cvList_type::size_type i = 0; i < cvList.cvList.size(); i++)
			os << *cvList.cvList[i] << std::endl;
		cvList.indent--;

		for(int i = 0; i < cvList.indent; i++)
			os << cvList.indentString;
		os << "</cvList>";

		return os;
	}
} /* namespace ImzML */
