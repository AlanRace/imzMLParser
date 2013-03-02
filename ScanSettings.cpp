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
#include "ScanSettings.h"

namespace ImzML {

	boost::shared_ptr<ImzML::CVParam> ScanSettings::getMaxCountPixelX() {
		return getCVParam(ImzML::Accession::maxCountPixelXID);
	}

	boost::shared_ptr<ImzML::CVParam> ScanSettings::getMaxCountPixelY() {
		return getCVParam(ImzML::Accession::maxCountPixelYID);
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::ScanSettings& scanSettings) {
		for(int i = 0; i < scanSettings.indent; i++)
			os << scanSettings.indentString;
		os << "<scanSettings id=\"" << scanSettings.id << "\">" << std::endl;

		scanSettings.indent++;
		os << (MzMLContent)scanSettings;
		scanSettings.indent--;

		for(int i = 0; i < scanSettings.indent; i++)
			os << scanSettings.indentString;
		os << "</scanSettings>";

		return os;
	}

} /* namespace ImzML */
