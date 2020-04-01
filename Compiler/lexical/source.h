#ifndef SOURCE_H
#define SOURCE_H

#include "string"

class Source
{
public:
	Source(std::string const& src);

	unsigned long line() const;

	unsigned long column() const;

	char current() const;

	char consume();

	bool end() const;
private:
	std::string m_source;
	std::string::const_iterator m_it;
	unsigned long m_line;
	unsigned long m_column;
};

#endif // SOURCE_H
