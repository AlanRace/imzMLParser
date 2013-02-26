/*
 * SourceFile.cpp
 *
 *  Created on: 5 Nov 2012
 *      Author: alan
 */

#include "SourceFile.h"

namespace ImzML {

	SourceFile::SourceFile(std::string id, std::string location, std::string name) {
		this->id = id;
		this->location = location;
		this->name = name;
	}


	std::ostream& operator<<(std::ostream& os, ImzML::SourceFile sourceFile) {
		for(int i = 0; i < sourceFile.indent; i++)
			os << sourceFile.indentString;

		os << "<sourceFile id=\"" << sourceFile.id << "\" location=\"" << sourceFile.location << "\" name=\"" << sourceFile.name << "\">" << std::endl;

		sourceFile.indent++;
		os << (MzMLContent)sourceFile;
		sourceFile.indent--;

		for(int i = 0; i < sourceFile.indent; i++)
			os << sourceFile.indentString;
		os << "</sourceFile>";

		return os;
	}
}


