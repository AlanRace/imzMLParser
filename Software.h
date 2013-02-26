#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <string>

#include "MzMLContent.h"
#include "OBOTerm.h"

namespace ImzML {

	class Software : public ImzML::MzMLContent
	{
		protected:
			std::string id;
//			ImzML::OBOTerm* software;
			std::string version;

		public:
			Software(std::string id, std::string version);
			virtual ~Software();

			std::string getID();
			std::string getVersion();

			friend std::ostream& operator<<(std::ostream& os, const ImzML::Software& software);
	};

} /* namespace ImzML */

#endif // SOFTWARE_H
