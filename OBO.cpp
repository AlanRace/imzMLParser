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
 * OBO.cpp
 *
 *  Created on: 31 Oct 2012
 *      Author: alan
 */

#include "OBO.h"
#include "helpers/trim.h"

#include <iostream>
#include <fstream>
#include <algorithm>

#include <cstdlib>

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>

namespace ImzML {

	OBO::OBO()
	{

	}

	OBO::OBO(std::string filename) {
		parse(filename);
	}

	OBO::~OBO()
	{
		cleanup();
	}

	void OBO::cleanup() {
		formatVersion = "";
		data = "";
		savedBy = "";
		autogeneratedBy = "";
		defaultNamespace = "";

		remarks.clear();
		terms.clear();
		imports.clear();
	}

	void OBO::parse(std::string filename) {
		// Make sure that the OBO doesn't have any data in it already
		cleanup();

        boost::filesystem::path filePath = boost::filesystem::path(filename);
        boost::filesystem::path dir = filePath.parent_path();

		std::ifstream oboFile;

		oboFile.open(filename.c_str());

		if(!oboFile) {
            OBOFileNotFound fileNotFound(filename);

            throw fileNotFound;
			std::cout << "ERROR: Could not open " << filename << std::endl;
		}

		std::string line;
		boost::shared_ptr<ImzML::OBOTerm> currentTerm;

		bool processingTerm = false;

		while(getline(oboFile, line)) {
			// Process a line

			// Trim the string
			trim(line);

			if(line.compare("[Term]") == 0) {
				processingTerm = true;

				// ID is on the next line
				getline(oboFile, line);

				line = line.substr(line.find(':') + 1);

				// Trim the string
				trim(line);

				//terms[line].reset(new ImzML::OBOTerm());

				currentTerm = boost::shared_ptr<ImzML::OBOTerm>(new ImzML::OBOTerm());
				currentTerm->setID(line);

				if(terms.size() == 0) {
					ns = line.substr(0, line.find(':'));
				}

				int number = std::atoi(line.substr(line.find(':') + 1).c_str());

				terms.insert(std::make_pair(number, currentTerm));
			} else if(line.compare("[Typedef]") == 0) {
				processingTerm = false;

				// TODO: Do something with typedefs
			} else if(processingTerm) {
				currentTerm->parseLine(line);
			} else {
				// Header information, so extract the tag and the value
				std::string tag = line.substr(0, line.find(':'));
				std::string value = line.substr(line.find(':') + 1);

				// Trim both the tag and the value
				trim(tag);
				trim(value);

				if(tag.compare("import") == 0) {
                    //
                    boost::filesystem::path import = dir / value;

                    imports.push_back(boost::shared_ptr<OBO>(new OBO(import.string())));
				}
			}
		}

		oboFile.close();

		std::map<int, boost::shared_ptr<ImzML::OBOTerm> >::iterator mapIterator;

		// Save all parents in the current OBO to speed up access
//		for(std::vector< boost::shared_ptr<OBO> >::iterator iter = imports.begin(); iter < imports.end(); iter++) {
//			for(mapIterator = (*iter)->terms.begin(); mapIterator != (*iter)->terms.end(); mapIterator++) {
//				terms.insert(std::make_pair((*mapIterator).first, (*mapIterator).second));
//			}
//		}

		// Now all terms have been loaded in we can process the relationships
		// and set up the necessary pointers

		for(mapIterator = terms.begin(); mapIterator != terms.end(); ++mapIterator) {
			if(!mapIterator->second)
				continue;

			// Set up parent/child relationship (is_a)
			std::vector< std::string >::iterator termVectorIterator;

			for(termVectorIterator = mapIterator->second->is_a.begin(); termVectorIterator < mapIterator->second->is_a.end(); termVectorIterator++) {
				boost::shared_ptr<ImzML::OBOTerm> parentTerm = getTerm(*termVectorIterator);

				if(parentTerm) {
					parentTerm->addChild(mapIterator->second);
					mapIterator->second->addParent(parentTerm);
				}
			}

			// Set up parent/child relationship (part_of)
			for(termVectorIterator = mapIterator->second->part_of.begin(); termVectorIterator < mapIterator->second->part_of.end(); termVectorIterator++) {
				boost::shared_ptr<ImzML::OBOTerm> parentTerm = getTerm(*termVectorIterator);

				if(parentTerm) {
					parentTerm->addChild(mapIterator->second);
					mapIterator->second->addParent(parentTerm);
				}
			}

			// Set up units
			for(termVectorIterator = mapIterator->second->has_units.begin(); termVectorIterator < mapIterator->second->has_units.end(); termVectorIterator++) {
				boost::shared_ptr <ImzML::OBOTerm> unitTerm = getTerm(*termVectorIterator);

				if(unitTerm) {
					mapIterator->second->addUnit(unitTerm);
				}
			}
		}
	}

	boost::shared_ptr<ImzML::OBOTerm> OBO::getTerm(std::string id) {
		if(id.empty())
			return boost::shared_ptr<ImzML::OBOTerm>();

		std::string ns = id.substr(0, id.find(':'));
		int number = std::atoi(id.substr(id.find(':') + 1).c_str());

		return getTerm(ns, number);
	}

	boost::shared_ptr<ImzML::OBOTerm> OBO::getTerm(std::string ns, int id) {
		if(ns.compare(this->ns) == 0) {
			return terms[id];
		}

        for(imports_type::size_type i = 0; i < imports.size(); i++) {
			boost::shared_ptr<ImzML::OBOTerm> term = imports[i]->getTerm(ns, id);

			if(term)
				return term;
		}

		return boost::shared_ptr<ImzML::OBOTerm>();
	}

} /* namespace ImzML */
