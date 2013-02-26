/*
 * Precursor.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef PRECURSOR_H_
#define PRECURSOR_H_

#include "MzMLContent.h"

namespace ImzML {

	class Precursor : public ImzML::MzMLContent {
	public:
		Precursor();
		virtual ~Precursor();
	};

} /* namespace ImzML */
#endif /* PRECURSOR_H_ */
