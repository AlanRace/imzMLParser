/*
 * CVList.cpp
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#include "CVList.h"

#include <iostream>

namespace ImzML {

	CVList::CVList(int count)
	{
		cvList.reserve(count);

	}

	CVList::~CVList()
	{
		// TODO Auto-generated destructor stub
	}

	void CVList::addCV(ImzML::CV* cv) {
		cvList.push_back(cv);
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::CVList& cvList) {
		for(int i = 0; i < cvList.indent; i++)
			os << cvList.indentString;
		os << "<cvList count=\"" << cvList.cvList.size() << "\">" << std::endl;

		cvList.indent++;
        for(ImzML::CVList::cvList_type::size_type i = 0; i < cvList.cvList.size(); i++)
			os << *cvList.cvList[i] << std::endl;
		cvList.indent--;

		for(int i = 0; i < cvList.indent; i++)
			os << cvList.indentString;
		os << "</cvList>";

		return os;
	}
} /* namespace ImzML */
