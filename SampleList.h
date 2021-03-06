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
