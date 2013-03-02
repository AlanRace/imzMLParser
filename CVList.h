/*
 *
 *  Copyright 2013 Alan Race
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *
 */
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
        typedef std::vector<ImzML::CV*> cvList_type;

        cvList_type cvList;

	public:
		CVList(int count);
		virtual ~CVList();

		void addCV(ImzML::CV* cv);

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const ImzML::CVList& cvLlist);
	};

} /* namespace ImzML */
#endif /* CVLIST_H_ */
