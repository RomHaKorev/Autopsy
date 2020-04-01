#include "illegalcharacterexception.h"

#include <sstream>

IllegalCharacterException::IllegalCharacterException(unsigned long line, unsigned long column, char c)
{
	std::stringstream ss;
	ss << "Illegal character '" << c << "' at line " << line + 1 << ", column " << column + 1;
	message = ss.str();
}

const char * IllegalCharacterException::what () const noexcept {

	return message.c_str();
}
