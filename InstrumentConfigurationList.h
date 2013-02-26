/*
 * InstrumentConfigurationList.h
 *
 *  Created on: 18 May 2012
 *      Author: Alan Race
 */

#ifndef INSTRUMENTCONFIGURATIONLIST_H_
#define INSTRUMENTCONFIGURATIONLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "InstrumentConfiguration.h"

#include <string>
#include <vector>

namespace ImzML {

	class InstrumentConfigurationList : public ImzML::MzMLContent {
		protected:
            typedef std::vector< boost::shared_ptr<ImzML::InstrumentConfiguration> > instrumentConfigurationList_type;

            instrumentConfigurationList_type instrumentConfigurationList;

		public:
			InstrumentConfigurationList(std::vector< boost::shared_ptr<ImzML::InstrumentConfiguration> >::size_type count);
			virtual ~InstrumentConfigurationList();

			void addInstrumentConfiguration(boost::shared_ptr<ImzML::InstrumentConfiguration> instrumentConfiguration);
			boost::shared_ptr<ImzML::InstrumentConfiguration> getInstrumentConfiguration(std::string id);
			boost::shared_ptr<ImzML::InstrumentConfiguration> getInstrumentConfiguration(int index);


			friend std::ostream& operator<<(std::ostream& os, const ImzML::InstrumentConfigurationList& icl);
	};

} /* namespace ImzML */

#endif /* INSTRUMENTCONFIGURATIONLIST_H_ */
