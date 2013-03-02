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
#ifndef BINARYDATAARRAY_H
#define BINARYDATAARRAY_H

#include <string>

#include <fstream>

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "DataProcessing.h"
#include "OBOTerm.h"

namespace ImzML {

	class BinaryDataArray : public ImzML::MzMLContent
	{
		protected:
			int arrayLength;
			ImzML::DataProcessing* dataProcessingRef;
			int encodedLength;

			// Location of the actual data
			std::string fileName;
			long offset;
			long size;

		public:

			BinaryDataArray(int encodedLength) : encodedLength(encodedLength) { }

			// Helper methods
			boost::shared_ptr<ImzML::CVParam> getDataType();
			boost::shared_ptr<ImzML::CVParam> getDataArrayType();
	
			long getExternalArrayLength();
			long getExternalEncodedLength();
			long getExternalOffset();
	
			bool isDoublePrecision();
			bool isSinglePrecision();
			bool isSigned8BitInteger();
			bool isSigned16BitInteger();
			bool isSigned32BitInteger();
			bool isSigned64BitInteger();

			bool isCompressed();

			int getDataTypeInBytes();
			static int getDataTypeInBytes(ImzML::CVParam* dataType);

			std::vector<double> getDouble(std::ifstream &ibd);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::BinaryDataArray& bda);

		private:
			char* getData(std::ifstream &ibd);
	};
} /* namespace ImzML */

#endif // BINARYDATAARRAY_H
