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
