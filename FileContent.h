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
#ifndef FILECONTENT_H
#define FILECONTENT_H

#include <string>

#include "MzMLContent.h"

namespace ImzML {

	class FileContent : public MzMLContent
	{
		public:
			static const std::string dataFileContentID;
			static const std::string binaryTypeID;
			static const std::string binaryTypeContinuous;
			static const std::string binaryTypeProcessed;

			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::FileContent& fileContent);
	};

} /* namespace ImzML */

#endif // FILECONTENT_H
