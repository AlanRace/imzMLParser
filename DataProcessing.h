/*
 *
 *  Copyright 2013 Alan Race
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *
 */
#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H

#include <string>
#include <vector>

#include "ProcessingMethod.h"

namespace ImzML {

	class DataProcessing : public ImzML::MzMLContent
	{
		protected:
            typedef std::vector< boost::shared_ptr<ImzML::ProcessingMethod> > processingMethods_type;

			std::string id;
            processingMethods_type processingMethods;

		public:
			DataProcessing(std::string id) : id(id) { }
			std::string getID() { return id; }

			void addProcessingMethod(boost::shared_ptr<ImzML::ProcessingMethod> processingMethod);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::DataProcessing& dataProcessing);
	};

} /* namespace ImzML */

#endif // DATAPROCESSING_H
