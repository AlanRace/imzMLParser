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
			std::vector< boost::shared_ptr<ImzML::Spectrum> > spectrumList;

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
