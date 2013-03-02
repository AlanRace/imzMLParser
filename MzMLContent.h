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
#ifndef MZMLCONTENT_H
#define MZMLCONTENT_H

#include <vector>
#include <map>
#include <iostream>

#include <boost/shared_ptr.hpp>

#include "CVParam.h"
#include "OBOTerm.h"

namespace ImzML {

	class ReferenceableParamGroup;

	class MzMLContent
	{
		protected:
            typedef std::vector<boost::shared_ptr<ImzML::ReferenceableParamGroup> > referenceableParamGroupRefs_type;

            referenceableParamGroupRefs_type referenceableParamGroupRefs;

			std::map<std::string, boost::shared_ptr<ImzML::CVParam> > cvParams;

		public:
			MzMLContent();
			MzMLContent(const MzMLContent& content);

			void addCvParam(boost::shared_ptr<ImzML::CVParam> oboTerm) {
				cvParams[oboTerm->getAccession()] = oboTerm;
			}

			void addReferenceableParamGroup(boost::shared_ptr<ImzML::ReferenceableParamGroup> rpg) {
				// TODO: Need to fix converter to prevent this happening
				if(rpg != NULL)
					referenceableParamGroupRefs.push_back(rpg);
			}

			boost::shared_ptr<ImzML::CVParam> getCVParam(std::string id);
			boost::shared_ptr<ImzML::CVParam> getCVParamOrChild(std::string id);
			std::vector<boost::shared_ptr<ImzML::CVParam> > getChildrenOf(std::string id);

			// Operators
			friend std::ostream& operator<<(std::ostream& os, const ImzML::MzMLContent& obj);
	
			// Used by the << operator to ensure correct indentation
			static int indent;
			static std::string indentString;
	};

} /* namespace ImzML */

#endif // MZMLCONTENT_H
