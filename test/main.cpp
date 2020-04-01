#include "gtest/gtest.h"
#include <lexical/lexer.h>

namespace {
TEST(LexerTests, SimpleNumber) {
	Lexer lexer;
	lexer << "123";
	EXPECT_EQ(std::list<Token>({Token(TokenType::Number, "123", Position(0, 0))}), lexer.tokens());
}

TEST(LexerTests, SimpleOperator) {
	Lexer lexer;
	lexer << "+";
	EXPECT_EQ(std::list<Token>({Token(TokenType::Operator, "+", Position(0, 0))}), lexer.tokens());
}

TEST(LexerTests, SimpleOperation) {
	Lexer lexer;
	lexer << "12 + 4";
	EXPECT_EQ(std::list<Token>({
								   Token(TokenType::Operator, "12", Position(0, 0)),
								   Token(TokenType::Operator, "+", Position(0, 3)),
								   Token(TokenType::Operator, "4", Position(0, 5))
							   }), lexer.tokens());
}

}


int main()
{
	 testing::InitGoogleTest();
	 return RUN_ALL_TESTS();
}
