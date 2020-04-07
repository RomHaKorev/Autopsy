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
	if (tokens.end())
		return;

	operand();
	tokens.consume(TokenType::Operator);
	operand();
}

void Parser::operand()
{
	if (tokens.is(TokenType::Operator, {"+", "-"}))
		tokens.consume();
	tokens.consume(TokenType::Number);
}
