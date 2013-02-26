/*
 * SoftwareList.cpp
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#include "SoftwareList.h"

namespace ImzML {

	SoftwareList::SoftwareList(std::vector< boost::shared_ptr<ImzML::Software> >::size_type count)
	{
		softwareList.reserve(count);

	}

	SoftwareList::~SoftwareList()
	{
		// TODO Auto-generated destructor stub
	}

	void SoftwareList::addSoftware(boost::shared_ptr<ImzML::Software> software) {
		softwareList.push_back(software);
	}

	boost::shared_ptr<ImzML::Software> SoftwareList::getSoftware(std::string id) {
		for(std::vector< boost::shared_ptr<ImzML::Software> >::iterator iter = softwareList.begin(); iter < softwareList.end(); iter++)
			if((*iter)->getID().compare(id) == 0)
				return *iter;

		return boost::shared_ptr<ImzML::Software>();
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::SoftwareList& softwareList) {
		for(int i = 0; i < softwareList.indent; i++)
			os << softwareList.indentString;
		os << "<softwareList count=\"" << softwareList.softwareList.size() << "\">" << std::endl;

		softwareList.indent++;
        for(ImzML::SoftwareList::softwareList_type::size_type i = 0; i < softwareList.softwareList.size(); i++)
			os << *softwareList.softwareList[i] << std::endl;
		softwareList.indent--;

		for(int i = 0; i < softwareList.indent; i++)
			os << softwareList.indentString;
		os << "</softwareList>";

		return os;
	}

} /* namespace ImzML */
