#include "lexer.h"

#include <algorithm>
#include <iostream>

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



IllegalCharacterException::IllegalCharacterException(unsigned long line, unsigned long column, char c)
{
	std::stringstream ss;
	ss << "Illegal character '" << c << "' at line " << line + 1 << ", column " << column + 1;
	message = ss.str();
}

const char * IllegalCharacterException::what () const noexcept {

	return message.c_str();
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
	char n = source.current();

	if (!(n >= '0' && n <= '9'))
		return false;

	std::string word = "";
	auto column = source.column();
	while (!source.end() && n >= '0' && n <= '9')
	{
	  word += n;
	  n = source.consume();
	}
	m_tokens << Token(Type::Number, word, Position(source.line(), column));

	return true;
}

bool Lexer::consumeOperator(Source& source)
{

	std::string word = "";
	char n = source.current();

	if (!( n == '=' || n == '+' || n == '-' || n == '*' || n == '/' || n == '<' || n == '>'))
		return false;

	word += n;
	n = source.consume();
	m_tokens << Token(Type::Operator, word, Position(source.line(), source.column() - word.size()));
	return true;


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
