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
        for(binaryDataArrayList_type::size_type i= 0; i < binaryDataArrayList.size(); i++) {

		}

	}

	void BinaryDataArrayList::addBinaryDataArray(boost::shared_ptr<ImzML::BinaryDataArray> binaryDataArray) {
		binaryDataArrayList.push_back(binaryDataArray);
	}

    boost::shared_ptr<ImzML::BinaryDataArray> BinaryDataArrayList::getBinaryDataArray(binaryDataArrayList_type::size_type index) {
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

        for(ImzML::BinaryDataArrayList::binaryDataArrayList_type::size_type i = 0; i < bdal.binaryDataArrayList.size(); i++)
			os << *bdal.binaryDataArrayList[i] << std::endl;

		bdal.indent--;

		for(int i = 0; i < bdal.indent; i++)
			os << bdal.indentString;
		os << "</binaryDataArrayList>";

		return os;
	}

} /* namespace ImzML */



