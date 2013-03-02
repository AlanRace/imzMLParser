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
