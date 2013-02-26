/*
 * Product.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include "MzMLContent.h"

namespace ImzML {

	class Product : public ImzML::MzMLContent {
	public:
		Product();
		virtual ~Product();
	};

} /* namespace ImzML */
#endif /* PRODUCT_H_ */
