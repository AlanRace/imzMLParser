/*
 * DataProcessingList.h
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#ifndef DATAPROCESSINGLIST_H_
#define DATAPROCESSINGLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "DataProcessing.h"

namespace ImzML {

	class DataProcessingList : public ImzML::MzMLContent {
	protected:
        typedef std::vector< boost::shared_ptr<ImzML::DataProcessing> > dataProcessingList_type;

        dataProcessingList_type dataProcessingList;

	public:
		DataProcessingList(int count);
		virtual ~DataProcessingList();

		void addDataProcessing(boost::shared_ptr<ImzML::DataProcessing> dataProcessing);
		boost::shared_ptr<ImzML::DataProcessing> getDataProcessing(int index);
		boost::shared_ptr<ImzML::DataProcessing> getDataProcessing(std::string id);

		friend std::ostream& operator<<(std::ostream& os, const ImzML::DataProcessingList& dpl);
	};

}

#endif /* DATAPROCESSINGLIST_H_ */
