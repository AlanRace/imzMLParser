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
 * SoftwareList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef SOFTWARELIST_H_
#define SOFTWARELIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"

#include "Software.h"

namespace ImzML {

	class SoftwareList : public ImzML::MzMLContent {
	private:
        typedef std::vector< boost::shared_ptr<Software> > softwareList_type;

        softwareList_type softwareList;

	public:
		SoftwareList(std::vector< boost::shared_ptr<ImzML::Software> >::size_type count);
		virtual ~SoftwareList();

		void addSoftware(boost::shared_ptr<ImzML::Software> software);

		boost::shared_ptr<ImzML::Software> getSoftware(std::string id);

		friend std::ostream& operator<<(std::ostream& os, const ImzML::SoftwareList& softwareList);
	};

} /* namespace ImzML */
#endif /* SOFTWARELIST_H_ */
