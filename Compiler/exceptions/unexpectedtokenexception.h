#ifndef UNEXPECTEDTOKENEXCEPTION_H
#define UNEXPECTEDTOKENEXCEPTION_H


#include <exception>
#include <string>


class UnexpectedTokenException: public std::exception
{
public:
	UnexpectedTokenException(int expected, int actual);
	virtual const char * what () const noexcept;

	std::string message;
};

#endif // UNEXPECTEDTOKENEXCEPTION_H
