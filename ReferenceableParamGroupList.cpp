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
/*
 * ReferenceableParamGroupList.cpp
 *
 *  Created on: 18 May 2012
 *      Author: Alan Race
 */

#include "ReferenceableParamGroupList.h"

namespace ImzML {

	ReferenceableParamGroupList::ReferenceableParamGroupList(int count)
	{
        referenceableParamGroupList.reserve(count);
	}

	ReferenceableParamGroupList::~ReferenceableParamGroupList()
	{
		// TODO Auto-generated destructor stub
	}

	void ReferenceableParamGroupList::addReferenceableParamGroup(boost::shared_ptr<ImzML::ReferenceableParamGroup> rpg) {
			referenceableParamGroupList.push_back(rpg);
	}

	int ReferenceableParamGroupList::size() {
			return referenceableParamGroupList.size();
	}

	boost::shared_ptr<ImzML::ReferenceableParamGroup> ReferenceableParamGroupList::getReferenceableParamGroup(std::string id) {

		for(std::vector< boost::shared_ptr<ImzML::ReferenceableParamGroup> >::iterator iter = referenceableParamGroupList.begin(); iter < referenceableParamGroupList.end(); iter++)
			if(id.compare((*iter)->getID()) == 0)
				return *iter;

		return boost::shared_ptr<ImzML::ReferenceableParamGroup>();
	}

	boost::shared_ptr<ImzML::ReferenceableParamGroup> ReferenceableParamGroupList::getReferenceableParamGroup(int index) {
		return referenceableParamGroupList[index];
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::ReferenceableParamGroupList& rpgList) {
		for(int i = 0; i < rpgList.indent; i++)
			os << rpgList.indentString;
		os << "<referenceableParamGroupList count=\"" << rpgList.referenceableParamGroupList.size() << "\">" << std::endl;

		rpgList.indent++;
        for(ImzML::ReferenceableParamGroupList::referenceableParamGroupList_type::size_type i = 0; i < rpgList.referenceableParamGroupList.size(); i++)
			os << *rpgList.referenceableParamGroupList[i];
		rpgList.indent--;

		for(int i = 0; i < rpgList.indent; i++)
			os << rpgList.indentString;
		os << "</referenceableParamGroupList>";

		return os;
	}

} /* namespace ImzML */
