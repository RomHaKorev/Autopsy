#ifndef TOKENSTACK_H
#define TOKENSTACK_H

#include <list>

#include "../lexical/tokens/token.h"


class TokenStack
{
public:
	TokenStack();
	TokenStack(std::list<Token> const&);
	TokenStack(TokenStack const&) = default;
	TokenStack& operator=(TokenStack const&) = default;

	Token consume();
	Token consume(TokenType type, std::initializer_list<std::string> = {});
	bool is(TokenType type, std::initializer_list<std::string> = {}) const;
	bool end() const;
private:
	std::list<Token> tokens;
};

#endif // TOKENSTACK_H
