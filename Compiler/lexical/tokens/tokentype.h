#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <map>

enum TokenType {
	Number = 0,
	String,
	Operator
};

std::ostream& operator<<(std::ostream& out, const TokenType value);
#endif // TOKENTYPE_H
