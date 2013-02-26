#ifndef DETECTOR_H
#define DETECTOR_H

#include <vector>
#include <string>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "OBOTerm.h"

namespace ImzML {

	class Detector : public ImzML::MzMLContent
	{
		protected:
			int order;

	
		public:
			static const std::string detectorTypeID;
			static const std::string detectorAttributeID;
			static const std::string detectorAcquisitionModeID;

			Detector(int order);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::Detector& detector);

	};

} /* namespace ImzML */
	
#endif // DETECTOR_H
