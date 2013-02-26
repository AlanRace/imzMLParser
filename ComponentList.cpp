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
		for(int i = 0; i < componentList.sources.size(); i++)
			os << *componentList.sources[i] << std::endl;
		for(int i = 0; i < componentList.analysers.size(); i++)
			os << *componentList.analysers[i] << std::endl;
		for(int i = 0; i < componentList.detectors.size(); i++)
			os << *componentList.detectors[i] << std::endl;
		componentList.indent--;

		for(int i = 0; i < componentList.indent; i++)
			os << componentList.indentString;
		os << "</componentList>";

		return os;
	}

} /* namespace ImzML */
