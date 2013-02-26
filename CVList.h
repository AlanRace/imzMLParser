/*
 * CVList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef CVLIST_H_
#define CVLIST_H_

#include "CV.h"
#include "MzMLContent.h"

#include <vector>

namespace ImzML {

	class CVList : public MzMLContent {
	private:
		std::vector<ImzML::CV*> cvList;

	public:
		CVList(int count);
		virtual ~CVList();

		void addCV(ImzML::CV* cv);

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const ImzML::CVList& cvLlist);
	};

} /* namespace ImzML */
#endif /* CVLIST_H_ */
