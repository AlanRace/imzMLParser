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
#ifndef RUN_H
#define RUN_H

#include <vector>
#include <string>

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"

#include "InstrumentConfiguration.h"
#include "Sample.h"
#include "DataProcessing.h"
#include "SpectrumList.h"
//#include "ChromatogramList.h"

namespace ImzML {

	class Run : public ImzML::MzMLContent
	{
		protected:
			boost::shared_ptr<ImzML::InstrumentConfiguration> defaultInstrumentConfigurationRef;
			// TODO: defaultSourceFileRef
			std::string id;
			boost::shared_ptr<ImzML::Sample> sampleRef;
			//Date startTimeStamp;

			// TODO: referenceableParamGroupRef
			// TODO: cvParam
			// TODO: userParam

			// defaultDataProcessingRef is for spectrumList
			boost::shared_ptr<ImzML::DataProcessing> defaultDataProcessingRef;
			boost::shared_ptr<ImzML::SpectrumList> spectrumList;
	//		ChromatogramList* chromatogramList;

		public:
	//		Run() {}
			Run(std::string id, boost::shared_ptr<ImzML::InstrumentConfiguration> defaultInstrumentConfigurationRef) {
				this->id = id;
				this->defaultInstrumentConfigurationRef = defaultInstrumentConfigurationRef;
			}

			void setSpectrumList(boost::shared_ptr<ImzML::SpectrumList> spectrumList) { this->spectrumList = spectrumList; }
	
			boost::shared_ptr<ImzML::SpectrumList> getSpectrumList() { return spectrumList; }


			friend std::ostream& operator<<(std::ostream& os, const ImzML::Run& run);
	};
	
} /* namespace ImzML */

#endif // RUN_H
