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
