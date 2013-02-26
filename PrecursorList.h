/*
 * PrecursorList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef PRECURSORLIST_H_
#define PRECURSORLIST_H_

#include "MzMLContent.h"

namespace ImzML {

	class PrecursorList : public ImzML::MzMLContent {
	public:
		PrecursorList();
		virtual ~PrecursorList();
	};

} /* namespace ImzML */
#endif /* PRECURSORLIST_H_ */
