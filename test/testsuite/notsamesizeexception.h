#ifndef NOTSAMESIZEEXCEPTION_H
#define NOTSAMESIZEEXCEPTION_H

#include <exception>
#include <sstream>

class NotSameSizeException: public std::exception {
public:
	NotSameSizeException(int expected, int result);
	virtual const char * what () const noexcept;
private:
	std::string message;
};

#endif // NOTSAMESIZEEXCEPTION_H
