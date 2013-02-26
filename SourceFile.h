#ifndef SOURCEFILE_H
#define SOURCEFILE_H

#include <string>

#include "MzMLContent.h"

namespace ImzML {

	class SourceFile : public ImzML::MzMLContent
	{
		protected:
			std::string id;
			std::string location;
			std::string name;

		public:
			SourceFile(std::string id, std::string location, std::string name);

			friend std::ostream& operator<<(std::ostream& os, ImzML::SourceFile sourceFile);
	};

} /* namespace ImzML */

#endif // SOURCEFILE_H
