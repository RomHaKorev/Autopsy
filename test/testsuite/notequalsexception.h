#ifndef NOTEQUALSEXCEPTION_H
#define NOTEQUALSEXCEPTION_H

#include <sstream>
#include <exception>


template<typename T> class NotEqualsException: public std::exception {
public:
	NotEqualsException(T expected, T result)
	{
		std::stringstream ss;
		ss << "Expecting '" << expected << "' to be equal to '" << result << "'";
		message = ss.str();
	}
	virtual const char * what () const noexcept { return message.c_str(); }
private:
	std::string message;
};


#endif // NOTEQUALSEXCEPTION_H
