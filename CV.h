/*
 * CV.h
 *
 *  Created on: 1 Nov 2012
 *      Author: alan
 */

#ifndef CV_H_
#define CV_H_

#include <string>

#include "MzMLContent.h"

namespace ImzML {

	class CV : public MzMLContent {
	private:
		std::string uri;
		std::string fullName;
		std::string id;
		std::string version;

	public:
		CV(std::string uri, std::string fullName, std::string id, std::string version);
		virtual ~CV();

		// Operators
		friend std::ostream& operator<<(std::ostream& os, const ImzML::CV& cv);
	};

} /* namespace ImzML */
#endif /* CV_H_ */
