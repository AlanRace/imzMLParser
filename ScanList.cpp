#include "ScanList.h"

namespace ImzML {

	ScanList::~ScanList() {
	}

	void ScanList::addScan(boost::shared_ptr<ImzML::Scan> scan) {
		scanList.push_back(scan);
	}

	boost::shared_ptr<ImzML::Scan> ScanList::getScan(int index) {
		return scanList[index];
	}

	int ScanList::size() {
		return scanList.size();
	}


	std::ostream& operator<<(std::ostream& os, const ImzML::ScanList& scanList) {
		for(int i = 0; i < scanList.indent; i++)
			os << scanList.indentString;
		os << "<scanList count=\"" << scanList.scanList.size() << "\">" << std::endl;

		scanList.indent++;
		os << (ImzML::MzMLContent&) scanList;

        for(ImzML::ScanList::scanList_type::size_type i = 0; i < scanList.scanList.size(); i++)
			os << *scanList.scanList[i] << std::endl;

		scanList.indent--;

		for(int i = 0; i < scanList.indent; i++)
			os << scanList.indentString;
		os << "</scanList>";

		return os;
	}

} /* namespace ImzML */
