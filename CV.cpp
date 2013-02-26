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
