#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <list>
#include <ostream>
#include <sstream>

#include "tokens/token.h"
#include "source.h"




std::ostream& operator<<(std::ostream& os, std::list<Token> const& list);

class Lexer
{
public:
	explicit Lexer();
	Lexer& operator<<(std::string);

	std::list<Token> const& tokens() const
	{
		return m_tokens;
	}

private:
	std::list<Token> m_tokens;

	bool consumeNumber(Source& source);
	bool consumeOperator(Source& source);
	void consumeSkippedCharacters(Source& source);
};

#endif // LEXER_H
