#include "source.h"

Source::Source(const std::string &src):
	m_source(src), m_it(m_source.begin()), m_line(0), m_column(0)
{}

unsigned long Source::line() const
{
	return m_line;
}

unsigned long Source::column() const
{
	return m_column;
}

char Source::current() const
{
	return *m_it;
}

char Source::consume()
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

bool Source::end() const
{
	return m_it == m_source.end();
}
