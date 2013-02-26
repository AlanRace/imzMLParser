/*
 * ReferenceableParamGroupList.h
 *
 *  Created on: 18 May 2012
 *      Author: Alan Race
 */

#ifndef REFERENCEABLEPARAMGROUPLIST_H_
#define REFERENCEABLEPARAMGROUPLIST_H_

#include <boost/shared_ptr.hpp>

#include "ReferenceableParamGroup.h"
#include "MzMLContent.h"

namespace ImzML {

	class ReferenceableParamGroupList : MzMLContent {
		protected:
			std::vector< boost::shared_ptr<ImzML::ReferenceableParamGroup> > referenceableParamGroupList;

		public:
			ReferenceableParamGroupList(int count);
			virtual ~ReferenceableParamGroupList();

			void addReferenceableParamGroup(boost::shared_ptr<ImzML::ReferenceableParamGroup> rpg);

			int size();

			boost::shared_ptr<ImzML::ReferenceableParamGroup> getReferenceableParamGroup(std::string id);
			boost::shared_ptr<ImzML::ReferenceableParamGroup> getReferenceableParamGroup(int index);


			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::ReferenceableParamGroupList& rpgList);
	};

} /* namespace ImzML */

#endif /* REFERENCEABLEPARAMGROUPLIST_H_ */
