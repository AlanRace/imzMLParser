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

		for(int i = 0; i < fileDescription.contacts.size(); i++)
			os << fileDescription.contacts[i] << std::endl;

		fileDescription.indent--;

		for(int j = 0; j < fileDescription.indent; j++)
			os << fileDescription.indentString;

		os << "</fileDescription>";

		return os;
	}
}


