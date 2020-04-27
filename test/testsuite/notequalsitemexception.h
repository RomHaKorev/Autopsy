#ifndef NOTEQUALSITEMEXCEPTION_H
#define NOTEQUALSITEMEXCEPTION_H

#include <sstream>
#include <exception>


template<typename T> class NotEqualsItemException: public std::exception {
public:
	NotEqualsItemException(int position, T expected, T result)
	{
		std::stringstream ss;
		ss << "At index" << position << ", expecting '" << expected << "' to be equal to '" << result << "'";
		message = ss.str();
	}
	virtual const char * what () const noexcept { return message.c_str(); }
private:
	std::string message;
};


#endif // NOTEQUALSITEMEXCEPTION_H
