/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, strange_characters_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ!!~~");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, whitespace_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("  ");
	ASSERT_EQ(2, actual);
}
TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, mixed_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aAbBcCdD");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aAbBcCdD");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, leading_mixed_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("DDd");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, trailing_mixed_case_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aaA");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, no_mixed_space_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AA AA");
	ASSERT_EQ(false, actual);
}