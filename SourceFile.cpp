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


