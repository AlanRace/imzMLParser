#include "InstrumentConfiguration.h"

namespace ImzML {

	const std::string InstrumentConfiguration::instrumentModelID = "MS:1000031";
	const std::string InstrumentConfiguration::instrumentAttributeID = "MS:1000496";
	const std::string InstrumentConfiguration::ionOpticsTypeID = "MS:1000597";
	const std::string InstrumentConfiguration::ionOpticsAttributeID = "MS:1000487";


	void InstrumentConfiguration::setComponentList(boost::shared_ptr<ImzML::ComponentList> componentList) {
		this->componentList = componentList;
	}

	void InstrumentConfiguration::setSoftwareRef(boost::shared_ptr<ImzML::Software> softwareRef) {
		this->softwareRef = softwareRef;
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::InstrumentConfiguration& ic) {
		for(int i = 0; i < ic.indent; i++)
			os << ic.indentString;
		os << "<instrumentConfiguration id=\"" << ic.id << "\">" << std::endl;

		ic.indent++;
		os << (MzMLContent)ic;

		if(ic.componentList != NULL)
			os << *ic.componentList << std::endl;

		if(ic.softwareRef != NULL) {
			for(int i = 0; i < ic.indent; i++)
				os << ic.indentString;

			os << "<softwareRef ref=\"" << ic.softwareRef->getID() << "\"/>" << std::endl;
		}

		ic.indent--;

		for(int i = 0; i < ic.indent; i++)
			os << ic.indentString;
		os << "</instrumentConfiguration>";

		return os;
	}

} /* namespace ImzML */
