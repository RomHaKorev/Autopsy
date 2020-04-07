#include "tokenstack.h"

#include "../exceptions/unexpectedtokenexception.h"


TokenStack::TokenStack()
{}

TokenStack::TokenStack(std::list<Token> const& tokens): tokens(tokens)
{}

Token TokenStack::consume()
{
	auto token = tokens.back();
	tokens.pop_back();
	return token;
}

Token TokenStack::consume(TokenType type, std::initializer_list<std::string> values)
{
	if (!is(type, values))
		throw UnexpectedTokenException(type, tokens.back().type);
	return consume();
}

bool TokenStack::is(TokenType type, std::initializer_list<std::string> values) const
{
	return	!end()
			&&
			(type == tokens.back().type)
			&&
			(values.size() == 0 ||
			std::find_if(values.begin(), values.end(), [this](std::string const& value) {
				return tokens.back().value == value;
			}) != values.end());
}


bool TokenStack::end() const
{
	return tokens.empty();
}
