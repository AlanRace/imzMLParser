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
 * CV.cpp
 *
 *  Created on: 1 Nov 2012
 *      Author: alan
 */

#include "CV.h"

#include <iostream>

namespace ImzML {

	CV::CV(std::string uri, std::string fullName, std::string id, std::string version)
	{
		this->uri = uri;
		this->fullName = fullName;
		this->id = id;
		this->version = version;
	}

	CV::~CV()
	{
		// TODO Auto-generated destructor stub
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::CV& cv) {
		for(int i = 0; i < cv.indent; i++)
			os << cv.indentString;

		os << "<cv uri=\"" << cv.uri << "\" fullName=\"" << cv.fullName << "\" id=\"" << cv.id << "\" version=\"" << cv.version << "\" />";

		return os;
	}

} /* namespace ImzML */
