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
		for(int i = 0; i < sourceFileList.sourceFileList.size(); i++)
			os << *sourceFileList.sourceFileList[i] << std::endl;
		sourceFileList.indent--;

		for(int i = 0; i < sourceFileList.indent; i++)
			os << sourceFileList.indentString;

		os << "</sourceFileList>";

		return os;
	}

} /* namespace ImzML */
