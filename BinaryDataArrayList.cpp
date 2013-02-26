/*
 * BinaryDataArrayList.cpp
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#include <iostream>

#include "BinaryDataArrayList.h"

namespace ImzML {
	BinaryDataArrayList::BinaryDataArrayList(std::vector< boost::shared_ptr<ImzML::BinaryDataArray> >::size_type count)
	{
		binaryDataArrayList.clear();
		binaryDataArrayList.reserve(count);
	}

	BinaryDataArrayList::~BinaryDataArrayList()
	{
		// TODO: Auto-generated
		for(int i= 0; i < binaryDataArrayList.size(); i++) {

		}

	}

	void BinaryDataArrayList::addBinaryDataArray(boost::shared_ptr<ImzML::BinaryDataArray> binaryDataArray) {
		binaryDataArrayList.push_back(binaryDataArray);
	}

	boost::shared_ptr<ImzML::BinaryDataArray> BinaryDataArrayList::getBinaryDataArray(int index) {
		if(index >= binaryDataArrayList.size())
			return boost::shared_ptr<ImzML::BinaryDataArray>();

		return binaryDataArrayList[index];
	}

	int BinaryDataArrayList::size() {
		return binaryDataArrayList.size();
	}

	boost::shared_ptr<ImzML::BinaryDataArray> BinaryDataArrayList::getMZArray() {
		for(std::vector< boost::shared_ptr<ImzML::BinaryDataArray> >::iterator iter = binaryDataArrayList.begin(); iter < binaryDataArrayList.end(); iter++) {
			boost::shared_ptr<ImzML::CVParam> mzArray = (*iter)->getCVParam(ImzML::Accession::mzArrayID);

			if(mzArray)
				return *iter;
		}

		return boost::shared_ptr<ImzML::BinaryDataArray>();
	}

	boost::shared_ptr<ImzML::BinaryDataArray> BinaryDataArrayList::getIntensityArray() {
		for(std::vector< boost::shared_ptr<ImzML::BinaryDataArray> >::iterator iter = binaryDataArrayList.begin(); iter < binaryDataArrayList.end(); iter++) {
			boost::shared_ptr<ImzML::CVParam> intensityArray = (*iter)->getCVParam(ImzML::Accession::intensityArrayID);

			if(intensityArray)
				return *iter;
		}

		return boost::shared_ptr<ImzML::BinaryDataArray>();
	}


	std::ostream& operator<<(std::ostream& os, const ImzML::BinaryDataArrayList& bdal) {
		for(int i = 0; i < bdal.indent; i++)
			os << bdal.indentString;
		os << "<binaryDataArrayList count=\"" << bdal.binaryDataArrayList.size() << "\">" << std::endl;

		bdal.indent++;

		for(int i = 0; i < bdal.binaryDataArrayList.size(); i++)
			os << *bdal.binaryDataArrayList[i] << std::endl;

		bdal.indent--;

		for(int i = 0; i < bdal.indent; i++)
			os << bdal.indentString;
		os << "</binaryDataArrayList>";

		return os;
	}

} /* namespace ImzML */



