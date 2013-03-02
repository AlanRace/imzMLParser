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
#ifndef SCANLIST_H
#define SCANLIST_H

#include <vector>

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"

#include "Scan.h"

namespace ImzML {

	class ScanList : public ImzML::MzMLContent
	{
		protected:
            typedef std::vector< boost::shared_ptr<ImzML::Scan> > scanList_type;

            scanList_type scanList;

		public:
            ScanList(int count) { scanList.reserve(count); }
			~ScanList();

			void addScan(boost::shared_ptr<Scan> scan);
			boost::shared_ptr<ImzML::Scan> getScan(int index);

			int size();

			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::ScanList& obj);
	};

} /* namespace ImzML */

#endif // SCANLIST_H
