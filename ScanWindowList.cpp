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
