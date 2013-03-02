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
