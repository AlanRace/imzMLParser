/*
 * Software.cpp
 *
 *  Created on: 1 Nov 2012
 *      Author: alan
 */

#include "Software.h"

namespace ImzML {

	Software::Software(std::string id, std::string version) {
		this->id = id;
		this->version = version;
	}

	Software::~Software() {

	}

	std::string Software::getID() {
		return id;
	}

	std::string Software::getVersion() {
		return version;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::Software& software) {
		for(int i = 0; i < software.indent; i++)
			os << software.indentString;
		os << "<software id=\"" << software.id << "\" version=\"" << software.version << "\">" << std::endl;

		software.indent++;
		os << (MzMLContent)software;
		software.indent--;

		for(int i = 0; i < software.indent; i++)
			os << software.indentString;
		os << "</software>";
		return os;
	}
}


