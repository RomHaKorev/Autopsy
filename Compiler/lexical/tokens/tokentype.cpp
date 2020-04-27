#include "tokentype.h"

#include <ostream>
#include <string>

std::ostream& operator<<(std::ostream& out, const TokenType value)
{
	static std::map<TokenType, std::string> strings;
	if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[TokenType::p] = #p
		INSERT_ELEMENT(String);
		INSERT_ELEMENT(Number);
		INSERT_ELEMENT(Operator);
#undef INSERT_ELEMENT
	}

	return out << strings[value];
}
