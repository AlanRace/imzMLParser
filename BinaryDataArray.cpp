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
#include "BinaryDataArray.h"
#include "helpers/convert.h"

namespace ImzML {

	boost::shared_ptr<ImzML::CVParam> BinaryDataArray::getDataType() {
		return getCVParam(ImzML::Accession::dataTypeID);
	}

	boost::shared_ptr<ImzML::CVParam> BinaryDataArray::getDataArrayType() {
		return getCVParam(ImzML::Accession::binaryDataArrayID);
	}

	long BinaryDataArray::getExternalArrayLength() {
		boost::shared_ptr<ImzML::CVParam> externalArrayLength = getCVParam(ImzML::Accession::externalArrayLengthID);

		if(externalArrayLength != NULL)
			return convertToLong(externalArrayLength->getValue());

		return 0;
	}

	long BinaryDataArray::getExternalEncodedLength() {
		boost::shared_ptr<ImzML::CVParam> externalEncodedLength = getCVParam(ImzML::Accession::externalEncodedLengthID);

		if(externalEncodedLength != NULL)
			return convertToLong(externalEncodedLength->getValue());

		return 0;
	}

	long BinaryDataArray::getExternalOffset() {
		boost::shared_ptr<ImzML::CVParam> externalOffset = getCVParam(ImzML::Accession::externalOffsetID);

		if(externalOffset != NULL)
			return convertToLong(externalOffset->getValue());

		return 0;
	}

	std::vector<double> BinaryDataArray::getDouble(std::ifstream &ibd) {
		char* buffer = getData(ibd);
		double* data = reinterpret_cast<double*>(buffer);

		return std::vector<double>(data, data+getExternalArrayLength());

//		long externalArrayLength = getExternalArrayLength();
//
//		for(int i = 0; i < externalArrayLength; i++)
//			dataVector.push_back(data[i]);
//
//		return dataVector;
	}

	char* BinaryDataArray::getData(std::ifstream &ibd) {
		ibd.seekg(getExternalOffset(), std::ios::beg);
		char* buffer = new char[getExternalEncodedLength()];

		ibd.read(buffer, getExternalEncodedLength());

//		if(isCompressed()) {
			// TODO: Convert and uncompress data if required
//		}

		return buffer;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::BinaryDataArray& bda) {
		for(int i = 0; i < bda.indent; i++)
			os << bda.indentString;
		os << "<binaryDataArray encodedLength=\"0\">" << std::endl;

		bda.indent++;
		os << (MzMLContent)bda;
		bda.indent--;

		for(int i = 0; i < bda.indent; i++)
			os << bda.indentString;
		os << "</binaryDataArray>";
		return os;
	}
}
