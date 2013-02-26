/*
 * TargetList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef TARGETLIST_H_
#define TARGETLIST_H_

#include "MzMLContent.h"

namespace ImzML {

	class TargetList : public ImzML::MzMLContent {
	public:
		TargetList();
		virtual ~TargetList();
	};

} /* namespace ImzML */
#endif /* TARGETLIST_H_ */
