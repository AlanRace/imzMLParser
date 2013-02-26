#include "Scan.h"

namespace ImzML {

	std::ostream& operator<<(std::ostream& os, const ImzML::Scan& scan) {
		for(int i = 0; i < scan.indent; i++)
			os << scan.indentString;
		os << "<scan>" << std::endl;

		scan.indent++;
		os << (ImzML::MzMLContent&) scan;

		scan.indent--;

		for(int i = 0; i < scan.indent; i++)
			os << scan.indentString;
		os << "</scan>";

		return os;
	}

} /* namespace ImzML */
