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
 * BinaryDataArrayList.h
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#ifndef BINARYDATAARRAYLIST_H_
#define BINARYDATAARRAYLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "BinaryDataArray.h"

namespace ImzML {

	class BinaryDataArrayList : public ImzML::MzMLContent {

	protected:
        typedef std::vector< boost::shared_ptr<BinaryDataArray> > binaryDataArrayList_type;

        binaryDataArrayList_type binaryDataArrayList;

	public:
		BinaryDataArrayList(std::vector< boost::shared_ptr<ImzML::BinaryDataArray> >::size_type count);
		virtual ~BinaryDataArrayList();

		void addBinaryDataArray(boost::shared_ptr<ImzML::BinaryDataArray> binaryDataArray);
        boost::shared_ptr<ImzML::BinaryDataArray> getBinaryDataArray(binaryDataArrayList_type::size_type index);

		int size();

		// Helper methods
		boost::shared_ptr<ImzML::BinaryDataArray> getMZArray();
		boost::shared_ptr<ImzML::BinaryDataArray> getIntensityArray();

		friend std::ostream& operator<<(std::ostream& os, const ImzML::BinaryDataArrayList& bdal);
	};

} /* namespace ImzML */

#endif /* BINARYDATAARRAYLIST_H_ */
