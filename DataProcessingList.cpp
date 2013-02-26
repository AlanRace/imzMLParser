/*
 * DataProcessingList.cpp
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#include "DataProcessingList.h"

namespace ImzML {

	DataProcessingList::DataProcessingList(int count) {
		dataProcessingList.reserve(count);
	}

	DataProcessingList::~DataProcessingList()
	{
		// TODO Auto-generated destructor stub
	}

	void DataProcessingList::addDataProcessing(boost::shared_ptr<ImzML::DataProcessing> dataProcessing) {
		dataProcessingList.push_back(dataProcessing);
	}

	boost::shared_ptr<ImzML::DataProcessing> DataProcessingList::getDataProcessing(int index) {
		return dataProcessingList[index];
	}

	boost::shared_ptr<ImzML::DataProcessing> DataProcessingList::getDataProcessing(std::string id) {
		for(std::vector< boost::shared_ptr<ImzML::DataProcessing> >::iterator iter = dataProcessingList.begin(); iter < dataProcessingList.end(); iter++)
			if(id.compare((*iter)->getID()) == 0)
				return *iter;

		return boost::shared_ptr<ImzML::DataProcessing>();
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::DataProcessingList& dpl) {
		for(int i = 0; i < dpl.indent; i++)
			os << dpl.indentString;
		os << "<dataProcessingList count=\"" << dpl.dataProcessingList.size() << "\">" << std::endl;

		dpl.indent++;
		for(int i = 0; i < dpl.dataProcessingList.size(); i++)
			os << *dpl.dataProcessingList[i] << std::endl;
		dpl.indent--;

		for(int i = 0; i < dpl.indent; i++)
			os << dpl.indentString;
		os << "</dataProcessingList>";

		return os;
	}

} /* namespace ImzML */

