#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <memory>
#include <list>

#include "tokens/assessable.h"

class Lexer
{
public:
	explicit Lexer();
	Lexer& operator<<(std::string);

private:
	std::unique_ptr<Assessable> input;


};

#endif // LEXER_H
