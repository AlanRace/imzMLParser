/*
 * SourceFileRefList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef SOURCEFILEREFLIST_H_
#define SOURCEFILEREFLIST_H_

#include "MzMLContent.h"

namespace ImzML {

	class SourceFileRefList : public ImzML::MzMLContent {
	public:
		SourceFileRefList();
		virtual ~SourceFileRefList();
	};

} /* namespace ImzML */
#endif /* SOURCEFILEREFLIST_H_ */
