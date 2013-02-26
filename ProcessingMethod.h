#ifndef PROCESSINGMETHOD_H
#define PROCESSINGMETHOD_H

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "Software.h"

namespace ImzML {

	class ProcessingMethod : public ImzML::MzMLContent
	{
		protected:
			int order;
			boost::shared_ptr<ImzML::Software> softwareRef;

	
		public:
			static const std::string dataTransformationID;
			static const std::string dataProcessingParameterID;

			ProcessingMethod(int order, boost::shared_ptr<ImzML::Software> softwareRef);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::ProcessingMethod& processingMethod);
	};

} /* namespace ImzML */

#endif // PROCESSINGMETHOD_H
