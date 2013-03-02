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
#ifndef IMZMLCV_H
#define IMZMLCV_H

namespace ImzML
{

	namespace Accession {

		// Scan Settings
		static const std::string lineScanDirectionID = "IMS:1000049";
		static const std::string scanDirectionID = "IMS:1000040";
		static const std::string scanPatternID = "IMS:1000041";
		static const std::string scanTypeID = "IMS:1000048";
		static const std::string imageID = " IMS:1000004";

		static const std::string maxCountPixelXID = "IMS:1000042";
		static const std::string maxCountPixelYID = "IMS:1000043";
		static const std::string maxDimensionXID = "IMS:1000044";
		static const std::string maxDimensionYID = "IMS:1000045";

		// Scan
		static const std::string scanAttributeID = "MS:1000503";
	// TODO: SORT THIS	static const std::string scanDirectionID = "MS:1000018";
		static const std::string scanLawID = "MS:1000019";
		static const std::string positionXID = "IMS:1000050";
		static const std::string positionYID = "IMS:1000051";
		static const std::string positionZID = "IMS:1000052";

		static const std::string scanStartTimeID = "MS:1000016";

		// Binary Data Array
		static const std::string compressionTypeID = "MS:1000572";
		static const std::string binaryDataArrayID = "MS:1000513";
		static const std::string dataTypeID = "MS:1000518";

		static const std::string mzArrayID = "MS:1000514";
		static const std::string intensityArrayID = "MS:1000515";

		static const std::string doublePrecisionID = "MS:1000523";
		static const std::string singlePrecisionID = "MS:1000521";

		static const std::string externalArrayLengthID = "IMS:1000103";
		static const std::string externalDataID = "IMS:1000101";
		static const std::string externalEncodedLengthID = "IMS:1000104";
		static const std::string externalOffsetID = "IMS:1000102";

	}

}


#endif // IMZMLCV_H
