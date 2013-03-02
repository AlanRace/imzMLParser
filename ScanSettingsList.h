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
 * ScanSettingsList.h
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#ifndef SCANSETTINGSLIST_H_
#define SCANSETTINGSLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "ScanSettings.h"

namespace ImzML {

	class ScanSettingsList : public ImzML::MzMLContent {

	protected:
        typedef std::vector< boost::shared_ptr<ImzML::ScanSettings> > scanSettingsList_type;

        scanSettingsList_type scanSettingsList;

	public:
		ScanSettingsList(int count);
		virtual ~ScanSettingsList();

		void addScanSettings(boost::shared_ptr<ImzML::ScanSettings> scanSettings);
		boost::shared_ptr<ImzML::ScanSettings> getScanSettings(int index);
		boost::shared_ptr<ImzML::ScanSettings> getScanSettings(std::string id);

		int size();

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const ImzML::ScanSettingsList& scanSettingsList);
	};

} /* namespace ImzML */

#endif /* SCANSETTINGSLIST_H_ */
