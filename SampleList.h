/*
 * SampleList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef SAMPLELIST_H_
#define SAMPLELIST_H_

#include "MzMLContent.h"

namespace ImzML {

	class SampleList : public ImzML::MzMLContent {
	public:
		SampleList();
		virtual ~SampleList();
	};

} /* namespace ImzML */
#endif /* SAMPLELIST_H_ */
