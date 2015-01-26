#include "Exception.h"
#include <sstream>

using namespace common;

std::string CodePosition::toString()const {
	std::stringstream ss;
	ss << File << " line" << Line << " function: " << Function << std::endl;
	return ss.str();
}