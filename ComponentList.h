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
        typedef std::vector< boost::shared_ptr<ImzML::Source> > sources_type;
        typedef std::vector< boost::shared_ptr<ImzML::Analyser> > analysers_type;
        typedef std::vector< boost::shared_ptr<ImzML::Detector> > detectors_type;

        sources_type sources;
        analysers_type analysers;
        detectors_type detectors;


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
