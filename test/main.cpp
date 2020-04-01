#include "gtest/gtest.h"
#include <lexer.h>

namespace {
TEST(LexerTests, SimpleNumber) {
	Lexer lexer;
	lexer << "123";
	EXPECT_EQ(std::list<Token>({Token(Type::Number, "123", Position(0, 0))}), lexer.tokens());
}
}


int main()
{
	 testing::InitGoogleTest();
	 return RUN_ALL_TESTS();
}
