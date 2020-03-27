#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <list>
#include <ostream>
#include <sstream>

#include "tokens/token.h"


class IllegalCharacterException: public std::exception {
public:
	IllegalCharacterException(int line, int column, char c)
	{
		std::stringstream ss;
		ss << "Illegal character '" << c << "' at line " << line << ", column " << column;
		message = ss.str();
	}

	const char * what () const throw () {

		return message.c_str();
	}
private:
	std::string message;
};


std::ostream& operator<<(std::ostream& os, std::list<Token> const& list);

class Source
{
public:
	Source(std::string const& src):
		m_source(src), m_it(m_source.begin()), m_line(1), m_column(1)
	{}

	int line() const
	{
		return m_line;
	}

	int column() const
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
			m_column = 1;
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
	int m_line;
	int m_column;
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
