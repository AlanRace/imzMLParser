#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <string>
#include <vector>

#include "ProcessingMethod.h"

namespace ImzML {

	class DataProcessing : public ImzML::MzMLContent
	{
		protected:
			std::string id;
			std::vector< boost::shared_ptr<ImzML::ProcessingMethod> > processingMethods;

		public:
			DataProcessing(std::string id) : id(id) { }
			std::string getID() { return id; }

			void addProcessingMethod(boost::shared_ptr<ImzML::ProcessingMethod> processingMethod);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::DataProcessing& dataProcessing);
	};

} /* namespace ImzML */

#endif // DATAPROCESSING_H
