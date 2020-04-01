#include "lexer.h"

#include <algorithm>
#include <iostream>

#include "exceptions/illegalcharacterexception.h"

std::ostream& operator<<(std::ostream& os, std::list<Token> const& list)
{
	for (Token const& token : list)
	{
		os << token << std::endl;
	}
	return os;
}


Lexer::Lexer()
{
}

std::list<Token>& operator<<(std::list<Token>& list, Token const t)
{
	list.push_back(t);
	return list;
}




Lexer& Lexer::operator<<(std::string code)
{
	Source source(code);
	while (!source.end())
	{
		consumeSkippedCharacters(source);
		bool ok = consumeNumber(source) || consumeOperator(source);

		if(!ok)
			throw IllegalCharacterException(source.line(), source.column(), source.current());
	}
	return *this;
}

bool Lexer::consumeNumber(Source& source)
{

	// TODO : Not implemented yet
	return false;
}

bool Lexer::consumeOperator(Source& source)
{
	// TODO : Not implemented yet
	return false;
}

void Lexer::consumeSkippedCharacters(Source& source)
{
	// TODO : Not implemented yet
}
