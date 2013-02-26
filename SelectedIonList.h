/*
 * SelectedIonList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef SELECTEDIONLIST_H_
#define SELECTEDIONLIST_H_

#include "MzMLContent.h"

namespace ImzML {

	class SelectedIonList : public ImzML::MzMLContent {
	public:
		SelectedIonList();
		virtual ~SelectedIonList();
	};

} /* namespace ImzML */
#endif /* SELECTEDIONLIST_H_ */
