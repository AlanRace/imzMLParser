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
 * SpectrumList.h
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#ifndef SPECTRUMLIST_H_
#define SPECTRUMLIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "Spectrum.h"

namespace ImzML {

	class SpectrumList : public ImzML::MzMLContent {

		protected:
            typedef std::vector< boost::shared_ptr<ImzML::Spectrum> > spectrumList_type;

            spectrumList_type spectrumList;

			boost::shared_ptr<ImzML::DataProcessing> defaultDataProcessingRef;

		public:
			SpectrumList(int count, boost::shared_ptr<ImzML::DataProcessing> defaultDataProcessingRef);
			virtual ~SpectrumList();

			boost::shared_ptr<ImzML::DataProcessing> getDefaultDataProcessingRef() { return defaultDataProcessingRef; }
			void addSpectrum(boost::shared_ptr<ImzML::Spectrum> spectrum);
			boost::shared_ptr<ImzML::Spectrum> getSpectrum(int index);

			int size();

			friend std::ostream& operator<<(std::ostream& os, const ImzML::SpectrumList& spectrumList);
	};

} /* namespace ImzML */

#endif /* SPECTRUMLIST_H_ */
