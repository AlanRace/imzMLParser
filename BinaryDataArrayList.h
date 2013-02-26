/*
 * BinaryDataArrayList.h
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#ifndef BINARYDATAARRAYLIST_H_
#define BINARYDATAARRAYLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "BinaryDataArray.h"

namespace ImzML {

	class BinaryDataArrayList : public ImzML::MzMLContent {

	protected:
		std::vector< boost::shared_ptr<BinaryDataArray> > binaryDataArrayList;

	public:
		BinaryDataArrayList(std::vector< boost::shared_ptr<ImzML::BinaryDataArray> >::size_type count);
		virtual ~BinaryDataArrayList();

		void addBinaryDataArray(boost::shared_ptr<ImzML::BinaryDataArray> binaryDataArray);
		boost::shared_ptr<ImzML::BinaryDataArray> getBinaryDataArray(int index);

		int size();

		// Helper methods
		boost::shared_ptr<ImzML::BinaryDataArray> getMZArray();
		boost::shared_ptr<ImzML::BinaryDataArray> getIntensityArray();

		friend std::ostream& operator<<(std::ostream& os, const ImzML::BinaryDataArrayList& bdal);
	};

} /* namespace ImzML */

#endif /* BINARYDATAARRAYLIST_H_ */
