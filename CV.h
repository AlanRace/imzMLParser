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
/*
 * CV.h
 *
 *  Created on: 1 Nov 2012
 *      Author: alan
 */

#ifndef CV_H_
#define CV_H_

#include <string>

#include "MzMLContent.h"

namespace ImzML {

	class CV : public MzMLContent {
	private:
		std::string uri;
		std::string fullName;
		std::string id;
		std::string version;

	public:
		CV(std::string uri, std::string fullName, std::string id, std::string version);
		virtual ~CV();

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const ImzML::CV& cv);
	};

} /* namespace ImzML */
#endif /* CV_H_ */
