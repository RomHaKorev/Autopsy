#ifndef PARSER_H
#define PARSER_H

#include "lexical/lexer.h"

class Parser
{
public:
	Parser();
	void process(std::list<Token const> const& tokens);
private:
	std::list<Token const> tokens;
};

#endif // PARSER_H
