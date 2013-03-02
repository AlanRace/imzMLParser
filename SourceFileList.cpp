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
 * SourceFileList.cpp
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#include "SourceFileList.h"

namespace ImzML {

	SourceFileList::SourceFileList(int count)
	{
		sourceFileList.reserve(count);
	}

	SourceFileList::~SourceFileList()
	{
		// TODO Auto-generated destructor stub
	}

	void SourceFileList::addSourceFile(boost::shared_ptr<ImzML::SourceFile> sourceFile) {
		sourceFileList.push_back(sourceFile);
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::SourceFileList& sourceFileList) {
		for(int i = 0; i < sourceFileList.indent; i++)
			os << sourceFileList.indentString;

		os << "<sourceFileList count=\"" << sourceFileList.sourceFileList.size() << "\">" << std::endl;

		sourceFileList.indent++;
        for(ImzML::SourceFileList::sourceFileList_type::size_type i = 0; i < sourceFileList.sourceFileList.size(); i++)
			os << *sourceFileList.sourceFileList[i] << std::endl;
		sourceFileList.indent--;

		for(int i = 0; i < sourceFileList.indent; i++)
			os << sourceFileList.indentString;

		os << "</sourceFileList>";

		return os;
	}

} /* namespace ImzML */
