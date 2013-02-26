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
		std::vector< boost::shared_ptr<SourceFile> > sourceFileList;

	public:
		SourceFileList(int count);
		virtual ~SourceFileList();

		void addSourceFile(boost::shared_ptr<SourceFile> sourceFile);

		friend std::ostream& operator<<(std::ostream& os, const ImzML::SourceFileList& sourceFileList);
	};

} /* namespace ImzML */
#endif /* SOURCEFILELIST_H_ */
