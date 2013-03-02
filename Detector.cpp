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
#include "Detector.h"

namespace ImzML {

	const std::string Detector::detectorTypeID = "MS:1000026";
	const std::string Detector::detectorAttributeID = "MS:1000481";
	const std::string Detector::detectorAcquisitionModeID = "MS:1000027";

	Detector::Detector(int order) {
		this->order = order;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::Detector& detector) {
		for(int i = 0; i < detector.indent; i++)
			os << detector.indentString;
		os << "<detector order=\"" << detector.order << "\">" << std::endl;

		detector.indent++;
		os << (MzMLContent)detector;
		detector.indent--;

		for(int i = 0; i < detector.indent; i++)
			os << detector.indentString;
		os << "</detector>";

		return os;
	}

} /* namespace ImzML */
