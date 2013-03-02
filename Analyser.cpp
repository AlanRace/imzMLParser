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
#include "Analyser.h"

namespace ImzML {

	const std::string Analyser::analyserTypeID = "MS:1000443";
	const std::string Analyser::analyserAttributeID = "MS:1000480";

	Analyser::Analyser(int order) {
		this->order = order;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::Analyser& analyser) {
		for(int i = 0; i < analyser.indent; i++)
			os << analyser.indentString;
		os << "<analyser order=\"" << analyser.order << "\">" << std::endl;

		analyser.indent++;
		os << (MzMLContent)analyser;
		analyser.indent--;

		for(int i= 0; i < analyser.indent; i++)
			os << analyser.indentString;
		os << "</analyser>";

		return os;
	}

} /* namespace ImzML */
