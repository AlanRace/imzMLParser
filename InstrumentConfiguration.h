#ifndef INSTRUMENTCONFIGURATION_H
#define INSTRUMENTCONFIGURATION_H

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"
#include "ComponentList.h"
#include "Software.h"

namespace ImzML {

	class InstrumentConfiguration : public ImzML::MzMLContent
	{
		protected:
			std::string filename;

			// Required
			std::string id;

			boost::shared_ptr<ImzML::ComponentList> componentList;
			boost::shared_ptr<ImzML::Software> softwareRef;

//			ImzML::OBOTerm* instrumentModel;

			// Optional
//			ImzML::OBOTerm* ionOpticsType;
//			Software* software;


	
		public:
			static const std::string instrumentModelID;
			static const std::string instrumentAttributeID;
			static const std::string ionOpticsTypeID;
			static const std::string ionOpticsAttributeID;
	
			InstrumentConfiguration(std::string id) : id(id) { }
			std::string getID() { return id; }

			void setComponentList(boost::shared_ptr<ImzML::ComponentList> componentList);
			void setSoftwareRef(boost::shared_ptr<ImzML::Software> softwareRef);

			friend std::ostream& operator<<(std::ostream& os, const ImzML::InstrumentConfiguration& ic);
	};

} /* namespace ImzML */

#endif // INSTRUMENTCONFIGURATION_H
