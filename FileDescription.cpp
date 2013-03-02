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
 * FileDescription.cpp
 *
 *  Created on: 2 Nov 2012
 *      Author: alan
 */

#include "FileDescription.h"

namespace ImzML {

	FileDescription::FileDescription() {
	}

	void FileDescription::setFileContent(boost::shared_ptr<ImzML::FileContent> fileContent) {
		this->fileContent = fileContent;
	}

	void FileDescription::setSourceFileList(boost::shared_ptr<ImzML::SourceFileList> sourceFileList) {
		this->sourceFileList = sourceFileList;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::FileDescription& fileDescription) {
		for(int j = 0; j < fileDescription.indent; j++)
			os << fileDescription.indentString;

		os << "<fileDescription>" << std::endl;

		fileDescription.indent++;

		if(fileDescription.fileContent)
			os << *fileDescription.fileContent << std::endl;

		if(fileDescription.sourceFileList)
			os << *fileDescription.sourceFileList << std::endl;

        for(ImzML::FileDescription::contacts_type::size_type i = 0; i < fileDescription.contacts.size(); i++)
			os << fileDescription.contacts[i] << std::endl;

		fileDescription.indent--;

		for(int j = 0; j < fileDescription.indent; j++)
			os << fileDescription.indentString;

		os << "</fileDescription>";

		return os;
	}
}


