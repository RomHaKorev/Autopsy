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
	m_tokens.clear();
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
	return false;
}

bool Lexer::consumeOperator(Source& source)
{
	return false;
}

void Lexer::consumeSkippedCharacters(Source& source)
{
	char n = source.current();
	while (!source.end())
	{
		if (n == '\t' || n == ' ' || n == '\n')
		{
			n = source.consume();
		}
		else
			break;
	}
}
