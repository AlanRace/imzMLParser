#ifndef ANALYSER_H
#define ANALYSER_H

#include <vector>
#include <string>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "OBOTerm.h"

namespace ImzML {

	class Analyser : public ImzML::MzMLContent
	{
		protected:
			int order;

	
		public:
			static const std::string analyserTypeID;
			static const std::string analyserAttributeID;

			Analyser(int order);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::Analyser& analyser);
	};

} /* namespace ImzML */

#endif // ANALYSER_H
