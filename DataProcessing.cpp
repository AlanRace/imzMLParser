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

		for(int i = 0; i < dataProcessing.processingMethods.size(); i++)
			os << *dataProcessing.processingMethods[i] << std::endl;

		for(int i = 0; i < dataProcessing.indent; i++)
			os << dataProcessing.indentString;
		os << "</dataProcessing>";

		return os;
	}
}


