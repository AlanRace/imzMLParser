/*
 * ProductList.h
 *
 *  Created on: 30 Oct 2012
 *      Author: alan
 */

#ifndef PRODUCTLIST_H_
#define PRODUCTLIST_H_

#include "MzMLContent.h"

namespace ImzML {

	class ProductList : public ImzML::MzMLContent {
	public:
		ProductList();
		virtual ~ProductList();
	};

} /* namespace ImzML */
#endif /* PRODUCTLIST_H_ */
