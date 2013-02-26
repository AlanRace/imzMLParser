/*
 * ScanSettingsList.h
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#ifndef SCANSETTINGSLIST_H_
#define SCANSETTINGSLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "ScanSettings.h"

namespace ImzML {

	class ScanSettingsList : public ImzML::MzMLContent {

	protected:
        typedef std::vector< boost::shared_ptr<ImzML::ScanSettings> > scanSettingsList_type;

        scanSettingsList_type scanSettingsList;

	public:
		ScanSettingsList(int count);
		virtual ~ScanSettingsList();

		void addScanSettings(boost::shared_ptr<ImzML::ScanSettings> scanSettings);
		boost::shared_ptr<ImzML::ScanSettings> getScanSettings(int index);
		boost::shared_ptr<ImzML::ScanSettings> getScanSettings(std::string id);

		int size();

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const ImzML::ScanSettingsList& scanSettingsList);
	};

} /* namespace ImzML */

#endif /* SCANSETTINGSLIST_H_ */
