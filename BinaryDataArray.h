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
