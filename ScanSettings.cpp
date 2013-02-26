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
