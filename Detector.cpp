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
