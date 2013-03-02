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
 * DataProcessingList.h
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#ifndef DATAPROCESSINGLIST_H_
#define DATAPROCESSINGLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "DataProcessing.h"

namespace ImzML {

	class DataProcessingList : public ImzML::MzMLContent {
	protected:
        typedef std::vector< boost::shared_ptr<ImzML::DataProcessing> > dataProcessingList_type;

        dataProcessingList_type dataProcessingList;

	public:
		DataProcessingList(int count);
		virtual ~DataProcessingList();

		void addDataProcessing(boost::shared_ptr<ImzML::DataProcessing> dataProcessing);
		boost::shared_ptr<ImzML::DataProcessing> getDataProcessing(int index);
		boost::shared_ptr<ImzML::DataProcessing> getDataProcessing(std::string id);

		friend std::ostream& operator<<(std::ostream& os, const ImzML::DataProcessingList& dpl);
	};

}

#endif /* DATAPROCESSINGLIST_H_ */
