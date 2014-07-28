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
 * ImzMLSpectrum.h
 *
 *  Created on: 18 May 2012
 *      Author: Alan Race
 */

#ifndef IMZMLSPECTRUM_H_
#define IMZMLSPECTRUM_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "DataProcessing.h"
#include "ScanList.h"
#include "BinaryDataArrayList.h"

namespace ImzML {

	class Spectrum : public ImzML::MzMLContent {

	protected:
		std::string id;
		int defaultArrayLength;
		int index;

		boost::shared_ptr<ImzML::DataProcessing> dataProcessing;
		boost::shared_ptr<ImzML::ScanList> scanList;

		boost::shared_ptr<ImzML::BinaryDataArrayList> binaryDataArrayList;

		// Used to access data, or if the stream isn't open then to open it
		std::ifstream *ibdStream;
		std::string ibdLocation;

		Spectrum();

	public:
		Spectrum(const ImzML::Spectrum& cvParam);
		Spectrum(std::string id, int defaultArrayLength, int index);
		virtual ~Spectrum();

		void setScanList(boost::shared_ptr<ImzML::ScanList> scanList) { this->scanList = scanList; }
		void setBinaryDataArrayList(boost::shared_ptr<ImzML::BinaryDataArrayList> binaryDataArrayList) {

			this->binaryDataArrayList = binaryDataArrayList;
		}

		boost::shared_ptr<ImzML::ScanList> getScanList() { return scanList; }
		boost::shared_ptr<ImzML::BinaryDataArrayList> getBinaryDataArrayList();

		// Helper methods
		int getX();
		int getY();
		int getZ();

		std::vector<double> getMZArray();
		std::vector<double> getMZArray(std::ifstream &ibd);
		std::vector<double> getIntensityArray();
		std::vector<double> getIntensityArray(std::ifstream &ibd);
		void getIntensityArray(std::ifstream &ibd, double* dataLocation);
        void getIntensityArray(std::ifstream &ibd, float* dataLocation);

		void setibdLocation(std::string ibdLocation, std::ifstream *ibdStream) {
			this->ibdLocation = ibdLocation;
			this->ibdStream = ibdStream;
		}

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const ImzML::Spectrum& obj);

		void operator=(const ImzML::Spectrum& spectrum);
	};

} /* namespace ImzML */

#endif /* IMZMLSPECTRUM_H_ */
