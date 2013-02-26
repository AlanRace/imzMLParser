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
