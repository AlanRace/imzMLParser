#include "FileContent.h"

namespace ImzML {

	const std::string FileContent::dataFileContentID = "MS:1000524";
	const std::string FileContent::binaryTypeID = "IMS:1000003";
	const std::string FileContent::binaryTypeContinuous = "IMS:1000030";
	const std::string FileContent::binaryTypeProcessed = "IMS:1000031";


	std::ostream& operator<<(std::ostream& os, const ImzML::FileContent& fileContent) {
		for(int i = 0; i < fileContent.indent; i++)
			os << fileContent.indentString;

		os << "<fileContent>" << std::endl;

		fileContent.indent++;
		os << (MzMLContent) fileContent;
		fileContent.indent--;

		for(int i = 0; i < fileContent.indent; i++)
			os << fileContent.indentString;

		os << "</fileContent>";

		return os;
	}
} /* namespace ImzML */
