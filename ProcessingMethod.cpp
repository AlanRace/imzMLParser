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
#include "ProcessingMethod.h"

namespace ImzML {

	const std::string ProcessingMethod::dataTransformationID = "MS:1000452";
	const std::string ProcessingMethod::dataProcessingParameterID = "MS:1000630";

	ProcessingMethod::ProcessingMethod(int order, boost::shared_ptr<ImzML::Software> softwareRef) {
		this->order = order;
		this->softwareRef = softwareRef;
	}


	std::ostream& operator<<(std::ostream& os, const ImzML::ProcessingMethod& processingMethod) {
		for(int i = 0; i < processingMethod.indent; i++)
			os << processingMethod.indentString;
		os << "<processingMethod order=\"" << processingMethod.order << "\" softwareRef=\"" << processingMethod.softwareRef->getID() << "\">" << std::endl;

		processingMethod.indent++;
		os << (MzMLContent)processingMethod;
		processingMethod.indent--;

		for(int i = 0; i < processingMethod.indent; i++)
			os << processingMethod.indentString;
		os << "</processingMethod>";

		return os;
	}

} /* namespace ImzML */
