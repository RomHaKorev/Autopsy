#ifndef NUMBER_H
#define NUMBER_H

#include <string>


enum Type {
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

struct Token
{
public:
	Token(Type type, std::string const& value, Position const& position);
	friend std::ostream& operator<<(std::ostream& os, Token const& token);
	bool operator==(Token const& other) const;

	Type const type;
	std::string const value;
	Position const position;
};

#endif // NUMBER_H
