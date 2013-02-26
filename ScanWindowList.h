/*
 * ScanWindowList.h
 *
 *  Created on: 22 May 2012
 *      Author: alan
 */

#ifndef SCANWINDOWLIST_H_
#define SCANWINDOWLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"

#include "ScanWindow.h"

namespace ImzML {

	class ScanWindowList : public ImzML::MzMLContent {

	protected:
		std::vector< boost::shared_ptr<ImzML::ScanWindow> > scanWindowList;

	public:
		ScanWindowList(std::vector< boost::shared_ptr<ImzML::ScanWindow> >::size_type count);
		virtual ~ScanWindowList();

		void addScanWindow(boost::shared_ptr<ImzML::ScanWindow> scanWindow);
	};

} /* namespace ImzML */

#endif /* SCANWINDOWLIST_H_ */
