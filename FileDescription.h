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
