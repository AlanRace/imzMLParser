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
 * ComponentList.cpp
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#include "ComponentList.h"

namespace ImzML {

	ComponentList::ComponentList(int count)
	{
		sources.reserve(count);
		analysers.reserve(count);
		detectors.reserve(count);
	}

	ComponentList::~ComponentList()
	{
		// TODO Auto-generated destructor stub
	}

	void ComponentList::addSource(boost::shared_ptr<ImzML::Source> source) {
		sources.push_back(source);
	}

	void ComponentList::addAnalyser(boost::shared_ptr<ImzML::Analyser> analyser) {
		analysers.push_back(analyser);
	}

	void ComponentList::addDetector(boost::shared_ptr<ImzML::Detector> detector) {
		detectors.push_back(detector);
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::ComponentList& componentList) {
		for(int i = 0; i < componentList.indent; i++)
			os << componentList.indentString;
		os << "<componentList count=\"" << (componentList.sources.size()+componentList.analysers.size()+componentList.detectors.size()) << "\">" << std::endl;

		componentList.indent++;
        for(ImzML::ComponentList::sources_type::size_type i = 0; i < componentList.sources.size(); i++)
			os << *componentList.sources[i] << std::endl;
        for(ImzML::ComponentList::analysers_type::size_type i = 0; i < componentList.analysers.size(); i++)
			os << *componentList.analysers[i] << std::endl;
        for(ImzML::ComponentList::detectors_type::size_type i = 0; i < componentList.detectors.size(); i++)
			os << *componentList.detectors[i] << std::endl;
		componentList.indent--;

		for(int i = 0; i < componentList.indent; i++)
			os << componentList.indentString;
		os << "</componentList>";

		return os;
	}

} /* namespace ImzML */
