#ifndef SAMPLE_H
#define SAMPLE_H

#include <vector>
#include <string>

namespace ImzML {

	class Sample : public ImzML::MzMLContent
	{
		protected:
			std::string id;
			std::string name;


	
	};

} /* namespace ImzML */

#endif // SAMPLE_H
