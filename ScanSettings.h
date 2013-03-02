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
#ifndef SCANSETTINGS_H
#define SCANSETTINGS_H

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ReferenceableParamGroup.h"

namespace ImzML {

	class ScanSettings : public ImzML::MzMLContent
	{
		protected:
			std::string id;

		public:
			ScanSettings(std::string id) : id(id) { }
			std::string getID() { return id; }
	
			// Helper methods
			boost::shared_ptr<ImzML::CVParam> getMaxCountPixelX();
			boost::shared_ptr<ImzML::CVParam> getMaxCountPixelY();

			friend std::ostream& operator<<(std::ostream& os, const ImzML::ScanSettings& scanSettings);
	};

} /* namespace ImzML */

#endif // SCANSETTINGS_H
