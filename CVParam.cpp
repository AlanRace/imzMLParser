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
 * CVParam.cpp
 *
 *  Created on: 31 Oct 2012
 *      Author: alan
 */

#include "CVParam.h"

namespace ImzML {

	// Copy constructor required for use in std::vector<> if reallocation occurs
	CVParam::CVParam(const CVParam& cvParam) {
		term = cvParam.term;
		units = cvParam.units;

		value = cvParam.value;
	}

	CVParam::CVParam(boost::shared_ptr<ImzML::OBOTerm> term, std::string value) {
		this->term = term;
		this->value = value;
	}

	CVParam::CVParam(boost::shared_ptr<ImzML::OBOTerm> term, std::string value, boost::shared_ptr<ImzML::OBOTerm> units) {
		this->term = term;
		this->value = value;
		this->units = units;
	}

	CVParam::CVParam(std::string accession, std::string name, std::string value) {
		this->value = value;

		term.reset(new ImzML::OBOTerm(accession, name));
	}

	CVParam::CVParam(std::string accession, std::string name, std::string value, std::string unitAccession, std::string unitName) {
		term.reset(new ImzML::OBOTerm(accession, name));

		this->value = value;

		units.reset(new ImzML::OBOTerm(unitAccession, unitName));
	}

	CVParam::~CVParam() {

	}

	void CVParam::operator=(const CVParam &cvParam) {
		term = cvParam.term;
		units = cvParam.units;

		value = cvParam.value;
	}

	boost::shared_ptr<ImzML::OBOTerm> CVParam::getTerm() {
		return term;
	}

	bool operator==(const CVParam &cvParam1, const CVParam &cvParam2) {
		bool unitsMatch = true;

		if(cvParam1.units == NULL && cvParam2.units == NULL)
			unitsMatch = true;
		else if(cvParam1.units != NULL && cvParam2.units != NULL)
			unitsMatch = *cvParam1.units == *cvParam2.units;
		else
			unitsMatch = false;

		return (*cvParam1.term == *cvParam2.term) &&
				unitsMatch &&
				cvParam1.value.compare(cvParam2.value) == 0;
	}

	bool operator!=(const CVParam &cvParam1, const CVParam &cvParam2) {
		return !(cvParam1 == cvParam2);
	}

} /* namespace ImzML */


