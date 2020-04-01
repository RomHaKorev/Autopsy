#ifndef ILLEGALCHARACTEREXCEPTION_H
#define ILLEGALCHARACTEREXCEPTION_H

#include <string>

class IllegalCharacterException: public std::exception {
public:
	IllegalCharacterException(unsigned long line, unsigned long column, char c);

	const char * what () const noexcept;
private:
	std::string message;
};

#endif // ILLEGALCHARACTEREXCEPTION_H
