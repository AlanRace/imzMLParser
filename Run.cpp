#include "Run.h"

namespace ImzML {


	std::ostream& operator<<(std::ostream& os, const ImzML::Run& run) {
		for(int i = 0; i < run.indent; i++)
			os << run.indentString;
		os << "<run defaultInstrumentConfigurationRef=\"" << run.defaultInstrumentConfigurationRef->getID() << "\" id=\"" << run.id << "\">" << std::endl;

		if(run.spectrumList != NULL)
			os << *run.spectrumList << std::endl;

		for(int i = 0; i < run.indent; i++)
			os << run.indentString;
		os << "</run>";

		return os;
	}
}
