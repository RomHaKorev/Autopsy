#ifndef TOKEN_H
#define TOKEN_H

#include <string>


enum TokenType {
	Number = 0,
	String,
	Operator
};

struct Position
{
	unsigned long line;
	unsigned long column;
	Position(unsigned long l, unsigned long c): line(l), column(c){}
	Position(Position const&) = default;
};

std::ostream& operator<<(std::ostream&, Position const& position);

struct Token
{
public:
	Token(TokenType type, std::string const& value, Position const& position);
	friend std::ostream& operator<<(std::ostream& os, Token const& token);
	bool operator==(Token const& other) const;

	TokenType const type;
	std::string const value;
	Position const position;
};

#endif // TOKEN_H
