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
#include "ReferenceableParamGroup.h"

#include <iostream>

namespace ImzML {

	std::ostream& operator<<(std::ostream& os, const ImzML::ReferenceableParamGroup& rpg) {
		for(int i = 0; i < rpg.indent; i++)
			os << rpg.indentString;
		os << "<referenceableParamGroup id=\"" << rpg.id << "\">" << std::endl;

		rpg.indent++;
		os << (MzMLContent)rpg;
		rpg.indent--;

		for(int i = 0; i < rpg.indent; i++)
			os << rpg.indentString;
		os << "</referenceableParamGroup>" << std::endl;

		return os;
	}

}
