#include "Source.h"

namespace ImzML {

	const std::string Source::ionisationTypeID = "MS:1000008";
	const std::string Source::sourceAttributeID = "MS:1000482";
	const std::string Source::inletTypeID = "MS:1000007";
	const std::string Source::sampleStageID = "IMS:1000002";

	Source::Source(int order) {
		this->order = order;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::Source& source) {
		for(int i = 0; i < source.indent; i++)
			os << source.indentString;
		os << "<source order=\"" << source.order << "\">" << std::endl;

		source.indent++;
		os << (MzMLContent)source;
		source.indent--;

		for(int i = 0; i < source.indent; i++)
			os << source.indentString;
		os << "</source>";

		return os;
	}

} /* namespace ImzML */
