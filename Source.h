#ifndef SOURCE_H
#define SOURCE_H

#include <vector>
#include <string>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "OBOTerm.h"

namespace ImzML {

	class Source : public ImzML::MzMLContent
	{
		protected:
			int order;

		public:
			static const std::string ionisationTypeID;
			static const std::string sourceAttributeID;
			static const std::string inletTypeID;
			static const std::string sampleStageID;

			Source(int order);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::Source& source);
	};

} /* namespace ImzML */

#endif // SOURCE_H
