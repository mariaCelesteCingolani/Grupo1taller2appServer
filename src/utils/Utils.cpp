#include "Utils.h"

#include <sstream>



std::string intToString(int number) {
	std::stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}
