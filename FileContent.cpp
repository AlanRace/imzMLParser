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
#include "FileContent.h"

namespace ImzML {

	const std::string FileContent::dataFileContentID = "MS:1000524";
	const std::string FileContent::binaryTypeID = "IMS:1000003";
	const std::string FileContent::binaryTypeContinuous = "IMS:1000030";
	const std::string FileContent::binaryTypeProcessed = "IMS:1000031";


	std::ostream& operator<<(std::ostream& os, const ImzML::FileContent& fileContent) {
		for(int i = 0; i < fileContent.indent; i++)
			os << fileContent.indentString;

		os << "<fileContent>" << std::endl;

		fileContent.indent++;
		os << (MzMLContent) fileContent;
		fileContent.indent--;

		for(int i = 0; i < fileContent.indent; i++)
			os << fileContent.indentString;

		os << "</fileContent>";

		return os;
	}
} /* namespace ImzML */
