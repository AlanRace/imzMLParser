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
 * SpectrumList.cpp
 *
 *  Created on: 18 May 2012
 *      Author: alan
 */

#include "SpectrumList.h"

#include <iostream>

namespace ImzML {

	SpectrumList::SpectrumList(int count,
			boost::shared_ptr<ImzML::DataProcessing> defaultDataProcessingRef) {
		this->defaultDataProcessingRef = defaultDataProcessingRef;

        spectrumList.reserve(count);
	}

	SpectrumList::~SpectrumList()
	{
		// TODO Auto-generated destructor stub
	}

	void SpectrumList::addSpectrum(boost::shared_ptr<ImzML::Spectrum> spectrum) {
		spectrumList.push_back(spectrum);
	}

	boost::shared_ptr<ImzML::Spectrum> SpectrumList::getSpectrum(int index) {
		return spectrumList[index];
	}

	int SpectrumList::size() {
		return spectrumList.size();
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::SpectrumList& spectrumList) {
        for(int i = 0; i < spectrumList.indent; i++)
			os << spectrumList.indentString;
		os << "<spectrumList count=\"" << spectrumList.spectrumList.size() << "\" defaultDataProcessingRef=\"" << spectrumList.defaultDataProcessingRef->getID() << "\">" << std::endl;

		spectrumList.indent++;
        for(ImzML::SpectrumList::spectrumList_type::size_type i = 0; i < spectrumList.spectrumList.size(); i++)
			os << *spectrumList.spectrumList[i] << std::endl;
		spectrumList.indent--;

        for(int i = 0; i < spectrumList.indent; i++)
			os << spectrumList.indentString;
		os << "</spectrumList>";

		return os;
	}

} /* namespace ImzML */
