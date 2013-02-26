#ifndef FILECONTENT_H
#define FILECONTENT_H

#include <string>

#include "MzMLContent.h"

namespace ImzML {

	class FileContent : public MzMLContent
	{
		public:
			static const std::string dataFileContentID;
			static const std::string binaryTypeID;
			static const std::string binaryTypeContinuous;
			static const std::string binaryTypeProcessed;

			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::FileContent& fileContent);
	};

} /* namespace ImzML */

#endif // FILECONTENT_H
