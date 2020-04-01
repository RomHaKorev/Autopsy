#include "token.h"


#include <ostream>



Token::Token(TokenType type, std::string const& value, Position const& position):
	type(type), value(value), position(position)
{
}

bool Token::operator==(Token const& other) const
{
	return this->type == other.type && this->value == other.value;
}

std::ostream& operator<<(std::ostream& os, Token const& token)
{
	os << "Token " <<  token.type << ": '" << token.value << "' @ " << token.position;
	return os;
}


std::ostream &operator<<(std::ostream& os, const Position &position)
{
	os << position.line << "; " << position.column;
}
