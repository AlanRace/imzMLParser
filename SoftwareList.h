/*
 * SoftwareList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef SOFTWARELIST_H_
#define SOFTWARELIST_H_

#include <boost/shared_ptr.hpp>

#include "MzMLContent.h"

#include "Software.h"

namespace ImzML {

	class SoftwareList : public ImzML::MzMLContent {
	private:
		std::vector< boost::shared_ptr<Software> > softwareList;

	public:
		SoftwareList(std::vector< boost::shared_ptr<ImzML::Software> >::size_type count);
		virtual ~SoftwareList();

		void addSoftware(boost::shared_ptr<ImzML::Software> software);

		boost::shared_ptr<ImzML::Software> getSoftware(std::string id);

		friend std::ostream& operator<<(std::ostream& os, const ImzML::SoftwareList& softwareList);
	};

} /* namespace ImzML */
#endif /* SOFTWARELIST_H_ */
