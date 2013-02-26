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
