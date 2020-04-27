#include "tokenstack.h"

#include "../exceptions/unexpectedtokenexception.h"

#include <iostream>

TokenStack::TokenStack()
{}

TokenStack::TokenStack(std::list<Token> const& tokens): tokens(tokens)
{}

static std::ostream& operator<<(std::ostream& os, std::list<Token> const& token)
{
	for (auto t: token)
	{
		os << t << " ";
	}
	return os;
}

Token TokenStack::consume()
{
	auto token = tokens.front();
	tokens.pop_front();
//	std::cout << "Reading " << token << " / " << tokens << std::endl;
	return token;
}

Token TokenStack::consume(TokenType type, std::initializer_list<std::string> values)
{
	if (!is(type, values))
		throw UnexpectedTokenException(type, tokens.front().type);
	return consume();
}

bool TokenStack::is(TokenType type, std::initializer_list<std::string> values) const
{
	return	!end()
			&&
			(type == tokens.front().type)
			&&
			(values.size() == 0 ||
			std::find_if(values.begin(), values.end(), [this](std::string const& value) {
				return tokens.front().value == value;
			}) != values.end());
}


bool TokenStack::end() const
{
	return tokens.empty();
}
