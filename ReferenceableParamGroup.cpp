#include "ReferenceableParamGroup.h"

#include <iostream>

namespace ImzML {

	std::ostream& operator<<(std::ostream& os, const ImzML::ReferenceableParamGroup& rpg) {
		for(int i = 0; i < rpg.indent; i++)
			os << rpg.indentString;
		os << "<referenceableParamGroup id=\"" << rpg.id << "\">" << std::endl;

		rpg.indent++;
		os << (MzMLContent)rpg;
		rpg.indent--;

		for(int i = 0; i < rpg.indent; i++)
			os << rpg.indentString;
		os << "</referenceableParamGroup>" << std::endl;

		return os;
	}

}
