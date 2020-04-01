#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <list>
#include <ostream>
#include <sstream>

#include "tokens/token.h"





std::ostream& operator<<(std::ostream& os, std::list<Token> const& list);

class Source
{
public:
	Source(std::string const& src):
		m_source(src), m_it(m_source.begin()), m_line(0), m_column(0)
	{}

	unsigned long line() const
	{
		return m_line;
	}

	unsigned long column() const
	{
		return m_column;
	}

	char current() const
	{
		return *m_it;
	}

	char consume()
	{
		if (*m_it == '\n')
		{
			m_column = 0;
			++m_line;
		}
		else
			++m_column;

		++m_it;
		return *m_it;
	}

	bool end() const
	{
		return m_it == m_source.end();
	}
private:
	std::string m_source;
	std::string::const_iterator m_it;
	unsigned long m_line;
	unsigned long m_column;
};

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
