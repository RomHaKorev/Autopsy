#ifndef UNEXPECTEDTOKENEXCEPTION_H
#define UNEXPECTEDTOKENEXCEPTION_H


#include <exception>
#include <string>

#include "lexical/tokens/tokentype.h"

class UnexpectedTokenException: public std::exception
{
public:
	UnexpectedTokenException(TokenType expected, TokenType actual);
	virtual const char * what () const noexcept;

	std::string message;
};

#endif // UNEXPECTEDTOKENEXCEPTION_H
