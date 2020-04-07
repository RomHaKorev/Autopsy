#include "parser.h"

 Parser::Parser()
{}

void Parser::process(std::list<Token> const& tokens)
{
	this->tokens = TokenStack(tokens);
	operation();
}


void Parser::operation()
{
}
