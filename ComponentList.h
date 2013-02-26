/*
 * ComponentList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef COMPONENTLIST_H_
#define COMPONENTLIST_H_

#include "MzMLContent.h"
#include "Source.h"
#include "Analyser.h"
#include "Detector.h"

namespace ImzML {

	class ComponentList : public MzMLContent {
	private:
		std::vector< boost::shared_ptr<ImzML::Source> > sources;
		std::vector< boost::shared_ptr<ImzML::Analyser> > analysers;
		std::vector< boost::shared_ptr<ImzML::Detector> > detectors;


	public:
		ComponentList(int count);
		virtual ~ComponentList();

		void addSource(boost::shared_ptr<ImzML::Source> source);
		void addAnalyser(boost::shared_ptr<ImzML::Analyser> analyser);
		void addDetector(boost::shared_ptr<ImzML::Detector> detector);

		friend std::ostream& operator<<(std::ostream& os, const ImzML::ComponentList& componentList);
	};

} /* namespace ImzML */
#endif /* COMPONENTLIST_H_ */
