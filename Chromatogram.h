#ifndef CHROMATOGRAM_H
#define CHROMATOGRAM_H

#include <string>
#include <vector>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"
#include "BinaryDataArray.h"

namespace ImzML {

	class Chromatogram : public ImzML::MzMLContent
	{
		protected:
			std::string id;
			int defaultArrayLength;
			std::vector<BinaryDataArray> binaryDataArrayList;
	};

} /* namespace ImzML */

#endif // CHROMATOGRAM_H
