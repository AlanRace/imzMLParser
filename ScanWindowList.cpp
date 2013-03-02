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
 * ScanWindowList.cpp
 *
 *  Created on: 22 May 2012
 *      Author: alan
 */

#include "ScanWindowList.h"

namespace ImzML {

	ScanWindowList::ScanWindowList(std::vector< boost::shared_ptr<ImzML::ScanWindow> >::size_type count)
	{
		scanWindowList.reserve(count);

	}

	ScanWindowList::~ScanWindowList()
	{
		// TODO Auto-generated destructor stub
	}

	void ScanWindowList::addScanWindow(boost::shared_ptr<ImzML::ScanWindow> scanWindow) {
		scanWindowList.push_back(scanWindow);
	}

} /* namespace ImzML */
