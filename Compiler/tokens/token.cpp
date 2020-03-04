#include "token.h"


#include <ostream>

Token::Token(Type type, std::string const& value):
	type(type), value(value)
{
}

bool Token::operator==(Token const& other) const
{
	return this->type == other.type && this->value == other.value;
}

std::ostream& operator<<(std::ostream& os, Token const& token)
{
	os << "Token " <<  token.type << ": '" << token.value << "'";
	return os;
}

