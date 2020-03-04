#ifndef NUMBER_H
#define NUMBER_H

#include <string>


enum Type {
	Number = 0,
	String,
	Operator
};

class Token
{
public:
	Token(Type type, std::string const& value);
	friend std::ostream& operator<<(std::ostream& os, Token const& token);
	bool operator==(Token const& other) const;
private:
	Type type;
	std::string const value;
};

#endif // NUMBER_H
