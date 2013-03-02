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
 * SourceFileList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef SOURCEFILELIST_H_
#define SOURCEFILELIST_H_

#include <vector>

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "SourceFile.h"

namespace ImzML {

	class SourceFileList : public ImzML::MzMLContent {
    private:
        typedef std::vector< boost::shared_ptr<SourceFile> > sourceFileList_type;

        sourceFileList_type sourceFileList;

	public:
		SourceFileList(int count);
		virtual ~SourceFileList();

		void addSourceFile(boost::shared_ptr<SourceFile> sourceFile);

		friend std::ostream& operator<<(std::ostream& os, const ImzML::SourceFileList& sourceFileList);
	};

} /* namespace ImzML */
#endif /* SOURCEFILELIST_H_ */
