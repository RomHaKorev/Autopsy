#include "../Compiler/lexical/lexer.h"

#include "testsuite/testsuite.h"

class TestHelper {
public:
	TestHelper(std::string const& input): input(input)
	{}
	TestHelper& when_I_read_it()
	{
		lexer << input;
		return *this;
	}

	TestHelper& then_I_should_get(std::list<Token> const& expected)
	{
		Assertions::assertEquals(expected, lexer.tokens());
		return *this;
	}
private:
	std::string const input;
	Lexer lexer;
};

TestHelper given_the_input(std::string const& input)
{
	return TestHelper(input);
}

int main()
{
	TestSuite tests;

	tests("Simple Number", [](){
		Lexer lexer;
		lexer << "123";
		Assertions::assertEquals(std::list<Token>({Token(TokenType::Number, "123", Position(0, 0))}), lexer.tokens());
	});

	tests("Simple Operator", [](){
		Lexer lexer;
		lexer << "+";
		Assertions::assertEquals(std::list<Token>({Token(TokenType::Operator, "+", Position(0, 0))}), lexer.tokens());
	});

	tests("Simple Operation", [](){
		given_the_input("12 + 4")
		.when_I_read_it()
		.then_I_should_get({
			Token(TokenType::Number, "12", Position(0, 0)),
			Token(TokenType::Operator, "+", Position(0, 3)),
			Token(TokenType::Number, "4", Position(0, 5))
		});
	});

	tests("Simple Operation", [](){

	});

	std::cout << tests;

	return 0;
}
