#ifndef SCAN_H
#define SCAN_H

#include <vector>
#include <string>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"

#include "ScanWindowList.h"

namespace ImzML {

class Scan : public ImzML::MzMLContent
{
	protected:
		boost::shared_ptr<ImzML::ScanWindowList> scanWindowList;

	public:

		void setScanWindowList(boost::shared_ptr<ImzML::ScanWindowList> scanWindowList) { this->scanWindowList = scanWindowList; }

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const ImzML::Scan& obj);
};

} /* namespace ImzML */

#endif // SCAN_H
