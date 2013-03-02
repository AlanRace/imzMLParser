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
#ifndef OBOTERM_H
#define OBOTERM_H

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

namespace ImzML {

	class OBOTerm {
		private:
			std::string id;
			std::string name;
			std::string def;
			std::string ns;
			std::string comment;

			std::vector<std::string> has_units;
			std::vector<std::string> is_a;
			std::vector<std::string> part_of;

			std::vector<boost::shared_ptr<OBOTerm> > children;
			std::vector<boost::shared_ptr<OBOTerm> > parents;
			std::vector<boost::shared_ptr<OBOTerm> > units;

		public:
			typedef boost::shared_ptr<OBOTerm> SharedPointer;

			OBOTerm();
			OBOTerm(std::string id, std::string name);

			std::string getID() { return id; }
			std::string getName() { return name; }
			std::string getNamespace() { return ns; }

			void setID(std::string id);
			void setName(std::string name);

			void addChild(boost::shared_ptr<OBOTerm> child);
			void addParent(boost::shared_ptr<OBOTerm> parent);
			void addUnit(boost::shared_ptr<OBOTerm> unit);

			bool isChildOf(std::string id);
			bool isParentOf(std::string id);

			std::vector<boost::shared_ptr<OBOTerm> > getChildren() { return children; }
			std::vector<boost::shared_ptr<OBOTerm> > getParents() { return parents; }

			friend class OBO;

			// Operators
			friend bool operator==(const OBOTerm &term1, const OBOTerm &term2);
			friend bool operator!=(const OBOTerm &term1, const OBOTerm &term2);

		private:
			void parseLine(std::string line);
	};

} /* namespace ImzML */
	
#endif // OBOTERM_H
