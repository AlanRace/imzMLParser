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
/*
 * InstrumentConfigurationList.cpp
 *
 *  Created on: 18 May 2012
 *      Author: Alan Race
 */

#include "InstrumentConfigurationList.h"

namespace ImzML {

	InstrumentConfigurationList::InstrumentConfigurationList(std::vector< boost::shared_ptr<ImzML::InstrumentConfiguration> >::size_type count)
	{
		instrumentConfigurationList.reserve(count);

	}

	InstrumentConfigurationList::~InstrumentConfigurationList()
	{
		// TODO Auto-generated destructor stub
	}

	void InstrumentConfigurationList::addInstrumentConfiguration(
		boost::shared_ptr<ImzML::InstrumentConfiguration> instrumentConfiguration) {

		instrumentConfigurationList.push_back(instrumentConfiguration);
	}

	boost::shared_ptr<ImzML::InstrumentConfiguration> InstrumentConfigurationList::getInstrumentConfiguration(
			std::string id) {

		for (std::vector< boost::shared_ptr<ImzML::InstrumentConfiguration> >::iterator iter = instrumentConfigurationList.begin(); iter < instrumentConfigurationList.end(); iter++)
			if(id.compare((*iter)->getID()) == 0)
				return *iter;

		return boost::shared_ptr<ImzML::InstrumentConfiguration>();
	}

	boost::shared_ptr<ImzML::InstrumentConfiguration> InstrumentConfigurationList::getInstrumentConfiguration(
			int index) {
		return instrumentConfigurationList[index];
	}

	std::ostream& operator<<(std::ostream& os, const ImzML::InstrumentConfigurationList& icl) {
		for(int i = 0; i < icl.indent; i++)
			os << icl.indentString;
		os << "<instrumentConfigurationList count=\"" << icl.instrumentConfigurationList.size() << "\">" << std::endl;

		icl.indent++;
        for(ImzML::InstrumentConfigurationList::instrumentConfigurationList_type::size_type i = 0; i < icl.instrumentConfigurationList.size(); i++)
			os << *icl.instrumentConfigurationList[i] << std::endl;
		icl.indent--;

		for(int i = 0; i < icl.indent; i++)
			os << icl.indentString;
		os << "</instrumentConfigurationList>";

		return os;
	}

} /* namespace ImzML */


