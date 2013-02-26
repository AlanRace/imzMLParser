#ifndef SCANLIST_H
#define SCANLIST_H

#include <vector>

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"

#include "Scan.h"

namespace ImzML {

	class ScanList : public ImzML::MzMLContent
	{
		protected:
            typedef std::vector< boost::shared_ptr<ImzML::Scan> > scanList_type;

            scanList_type scanList;

		public:
            ScanList(int count) { scanList.reserve(count); }
			~ScanList();

			void addScan(boost::shared_ptr<Scan> scan);
			boost::shared_ptr<ImzML::Scan> getScan(int index);

			int size();

			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::ScanList& obj);
	};

} /* namespace ImzML */

#endif // SCANLIST_H
