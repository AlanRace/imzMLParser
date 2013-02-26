#ifndef REFERENCEABLEPARAMGROUP_H
#define REFERENCEABLEPARAMGROUP_H

#include <string>

#include "MzMLContent.h"

namespace ImzML {

	class ReferenceableParamGroup : public ImzML::MzMLContent {
		protected:
			std::string id;

		public:
			ReferenceableParamGroup(std::string id) : id(id) {}

			std::string getID() { return id; }

			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::ReferenceableParamGroup& rpg);
	};

} /* namespace ImzML */

#endif // REFERENCEABLEPARAMGROUP_H
