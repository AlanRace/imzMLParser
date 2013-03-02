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
 * DataProcessing.cpp
 *
 *  Created on: 5 Nov 2012
 *      Author: alan
 */

#include "DataProcessing.h"

namespace ImzML {

	void DataProcessing::addProcessingMethod(boost::shared_ptr<ImzML::ProcessingMethod> processingMethod) {
		processingMethods.push_back(processingMethod);
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::DataProcessing& dataProcessing) {
		for(int i = 0; i < dataProcessing.indent; i++)
			os << dataProcessing.indentString;
		os << "<dataProcessing id=\"" << dataProcessing.id << "\">" << std::endl;

        for(ImzML::DataProcessing::processingMethods_type::size_type i = 0; i < dataProcessing.processingMethods.size(); i++)
			os << *dataProcessing.processingMethods[i] << std::endl;

		for(int i = 0; i < dataProcessing.indent; i++)
			os << dataProcessing.indentString;
		os << "</dataProcessing>";

		return os;
	}
}


