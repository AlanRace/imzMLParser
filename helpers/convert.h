/*
 * convert.h
 *
 *  Created on: 21 May 2012
 *      Author: alan
 */

#ifndef CONVERT_H_
#define CONVERT_H_

// File: convert.h
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

 class BadConversion : public std::runtime_error {
 public:
   BadConversion(std::string const& s)
     : std::runtime_error(s)
     { }
 };

 inline double convertToDouble(std::string const& s)
 {
   std::istringstream i(s);
   double x;
   if (!(i >> x))
     throw BadConversion("convertToDouble(\"" + s + "\")");
   return x;
 }

 inline long convertToLong(std::string const& s)
 {
   std::istringstream i(s);
   long x;
   if (!(i >> x))
     throw BadConversion("convertToLong(\"" + s + "\")");
   return x;
 }

 inline double  endianSwap(double x)
 {
	 double retVal;
	 char *floatToConvert = ( char* ) & x;
	 char *returnFloat = ( char* ) & retVal;

	 // swap the bytes into a temporary buffer
	 returnFloat[0] = floatToConvert[7];
	 returnFloat[1] = floatToConvert[6];
	 returnFloat[2] = floatToConvert[5];
	 returnFloat[3] = floatToConvert[4];
	 returnFloat[4] = floatToConvert[3];
	 returnFloat[5] = floatToConvert[2];
	 returnFloat[6] = floatToConvert[1];
	 returnFloat[7] = floatToConvert[0];

	 return retVal;
 }


#endif /* CONVERT_H_ */
