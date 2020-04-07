#include "unexpectedtokenexception.h"

#include <sstream>

UnexpectedTokenException::UnexpectedTokenException(int expected, int actual)
{
	std::stringstream ss;
	ss << "Expected " << expected << " but found " << actual;
	message = ss.str();
}

const char * UnexpectedTokenException::what () const noexcept {
	return message.c_str();
}