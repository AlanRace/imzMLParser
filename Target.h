/*
 * Target.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef TARGET_H_
#define TARGET_H_

#include "MzMLContent.h"

namespace ImzML {

	class Target : public ImzML::MzMLContent {
	public:
		Target();
		virtual ~Target();
	};

} /* namespace ImzML */
#endif /* TARGET_H_ */
