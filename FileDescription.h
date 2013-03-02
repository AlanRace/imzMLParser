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
#ifndef FILEDESCRIPTION_H
#define FILEDESCRIPTION_H

#include <vector>

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "FileContent.h"
#include "SourceFileList.h"
#include "Contact.h"

namespace ImzML {

	class FileDescription : public ImzML::MzMLContent {
		protected:
            typedef std::vector< boost::shared_ptr<ImzML::Contact> > contacts_type;

			boost::shared_ptr<ImzML::FileContent> fileContent;
			boost::shared_ptr<ImzML::SourceFileList> sourceFileList;
            contacts_type contacts;

		public:
			FileDescription();

			void setFileContent(boost::shared_ptr<ImzML::FileContent> fileContent);
			boost::shared_ptr<ImzML::FileContent> getFileContent();

			void setSourceFileList(boost::shared_ptr<ImzML::SourceFileList> sourceFileList);
			boost::shared_ptr<ImzML::SourceFileList> getSourceFileList();

			void addContact(boost::shared_ptr<ImzML::Contact> contact);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::FileDescription& fileDescription);
	};

} /* namespace ImzML */

#endif // FILEDESCRIPTION_H
