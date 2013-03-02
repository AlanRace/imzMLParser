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
