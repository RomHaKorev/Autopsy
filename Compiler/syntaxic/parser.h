#ifndef PARSER_H
#define PARSER_H

#include "lexical/lexer.h"

#include "tokenstack.h"


class Parser
{
public:
	Parser();
	void process(std::list<Token> const& tokens);
private:
	TokenStack tokens;

	void operation();
	void operand();
};

#endif // PARSER_H
