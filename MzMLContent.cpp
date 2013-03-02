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
#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"

typedef std::vector< boost::shared_ptr<ImzML::CVParam> > CVParamSharedPointerVector;
typedef std::vector< boost::shared_ptr<ImzML::ReferenceableParamGroup> > RPGSharedPointerVector;

namespace ImzML {

	int ImzML::MzMLContent::indent = 0;
	std::string ImzML::MzMLContent::indentString = "  ";

	MzMLContent::MzMLContent() {
	}

	MzMLContent::MzMLContent(const MzMLContent& content) {
		referenceableParamGroupRefs = content.referenceableParamGroupRefs;
		cvParams = content.cvParams;
	}

	boost::shared_ptr<ImzML::CVParam> MzMLContent::getCVParam(std::string id) {
		for(RPGSharedPointerVector::iterator iter = referenceableParamGroupRefs.begin(); iter < referenceableParamGroupRefs.end(); iter++) {
			boost::shared_ptr<ImzML::CVParam> param = (*iter)->getCVParam(id);

			if(param)
				return param;
		}

//		for(CVParamSharedPointerVector::iterator iter = cvParams.begin(); iter < cvParams.end(); iter++)
//			if(id.compare((*iter)->getAccession()) == 0)
//				return *iter;

		return cvParams[id];
	}

	boost::shared_ptr<ImzML::CVParam> MzMLContent::getCVParamOrChild(std::string id) {
        for(referenceableParamGroupRefs_type::size_type i = 0; i < referenceableParamGroupRefs.size(); i++) {

		}
	}

	std::vector<boost::shared_ptr<ImzML::CVParam> > MzMLContent::getChildrenOf(std::string id) {
		CVParamSharedPointerVector children;

		for(RPGSharedPointerVector::iterator iter = referenceableParamGroupRefs.begin(); iter < referenceableParamGroupRefs.end(); iter++) {
			if(!*iter)
				continue;

			CVParamSharedPointerVector rpgChildren = (*iter)->getChildrenOf(id);

			// Add any children found the the ReferenceableParamGroups to the list
			children.insert(children.end(), rpgChildren.begin(), rpgChildren.end());
		}

//		for(CVParamSharedPointerVector::iterator iter = cvParams.begin(); iter < cvParams.end(); iter++) {
//			if((*iter)->getTerm()->isChildOf(id))
//				children.push_back(*iter);
//		}

		if(cvParams[id])
			children.push_back(cvParams[id]);

		// TODO: Check userParams

		return children;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::MzMLContent& obj) {
        for(ImzML::MzMLContent::referenceableParamGroupRefs_type::size_type i = 0; i < obj.referenceableParamGroupRefs.size(); i++) {
			for(int j = 0; j < obj.indent; j++)
				os << obj.indentString;

			os << "<referenceableParamGroup id=\"" << obj.referenceableParamGroupRefs[i]->getID() << "\" />" << std::endl;
		}

		for(std::map<std::string, boost::shared_ptr<ImzML::CVParam> >::const_iterator iter = obj.cvParams.begin();
				iter != obj.cvParams.end();
				iter++) {
			for(int j = 0; j < obj.indent; j++)
				os << obj.indentString;

			os << *iter->second << std::endl;
		}

		return os;
	}

} /* namespace ImzML */


