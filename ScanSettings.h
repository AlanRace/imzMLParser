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
