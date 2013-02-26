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
		for(int i = 0; i < spectrumList.spectrumList.size(); i++)
			os << *spectrumList.spectrumList[i] << std::endl;
		spectrumList.indent--;

		for(int i = 0; i < spectrumList.indent; i++)
			os << spectrumList.indentString;
		os << "</spectrumList>";

		return os;
	}

} /* namespace ImzML */
