/*
 * OBOTerm.cpp
 *
 *  Created on: 31 Oct 2012
 *      Author: alan
 */

#include "OBOTerm.h"
#include "../helpers/trim.h"

#include <string>
#include <iostream>
#include <algorithm>

namespace ImzML {

	OBOTerm::OBOTerm() {
	}

	OBOTerm::OBOTerm(std::string id, std::string name) {
		setID(id);
		setName(name);
	}

	void OBOTerm::setID(std::string id) {
		std::cout << this->id;
		this->id = id;

		// Extract the namespace from the ID
		this->ns = id.substr(0, id.find(':'));
		// Trim the string
		trim(this->ns);
	}

	void OBOTerm::setName(std::string name) {
		this->name = name;
	}

	void OBOTerm::parseLine(std::string line) {
		// Term information, so extract the tag and the value
		std::string tag = line.substr(0, line.find(':'));
		std::string value = line.substr(line.find(':') + 1);

		// Strip off comments
		value = value.substr(0, value.find('!'));

		// Trim both the tag and the value
		trim(tag);
		trim(value);

		if(tag.compare("name") == 0) {
			this->name = value;
		} else if(tag.compare("namespace") == 0) {
			this->ns = value;
		} else if(tag.compare("def") == 0) {
			this->def = value;
		} else if(tag.compare("comment") == 0) {
			this->comment = value;
		} else if(tag.compare("relationship") == 0) {
			std::string relationshipTag = value.substr(0, value.find(' '));
			std::string relationshipValue = value.substr(value.find(' ') + 1);

			if(relationshipTag.compare("is_a") == 0) {
				this->is_a.push_back(relationshipValue);
			} else if(relationshipTag.compare("has_units") == 0) {
				this->has_units.push_back(relationshipValue);
			} else if(relationshipTag.compare("part_of") == 0) {
				this->part_of.push_back(relationshipValue);
			}
		} else if(tag.compare("is_a") == 0) {
			this->is_a.push_back(value);
		}
	}

	void OBOTerm::addChild(boost::shared_ptr<OBOTerm> child) {
		if(child)
			children.push_back(child);
	}

	void OBOTerm::addParent(boost::shared_ptr<OBOTerm> parent) {
		if(parent)
			parents.push_back(parent);
	}

	void OBOTerm::addUnit(boost::shared_ptr<OBOTerm> unit) {
		if(unit)
			units.push_back(unit);
	}

	bool OBOTerm::isChildOf(std::string id) {
		bool isChild = false;

		for(std::vector<boost::shared_ptr<OBOTerm> >::iterator iter = parents.begin(); iter < parents.end(); iter++) {
			if((*iter)->id.compare(id) == 0)
				return true;

			isChild = (*iter)->isChildOf(id);

			if(isChild)
				return true;
		}

		return isChild;
	}

	bool operator==(const OBOTerm &term1, const OBOTerm &term2) {
		return term1.id.compare(term2.id) == 0;
	}

	bool operator!=(const OBOTerm &term1, const OBOTerm &term2) {
		return !(term1 == term2);
	}

} /* namespace ImzML */



