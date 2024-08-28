#include <gtest/gtest.h>
#include <str-utils-static.hpp>

TEST(Testing_get_message, Format_Is_Empty)
{
	const char* form = "";
	int i{ 5 };
	std::string astr{ "A test string" };
	auto m = get_message(form, i, astr.c_str());
	EXPECT_STREQ(m.c_str(), "");
}

TEST(Testing_get_message, Integers)
{
	const char* form = "Format test %i == %i";
	int i{ 5 };
	int j{ -5 };
	auto m = get_message(form, i, j);
	EXPECT_STREQ(m.c_str(), "Format test 5 == -5");
}

TEST(Testing_get_message, Strings)
{
	const char* form = "Format test %s follows %s.";
	std::string astr1{ "a test string" };
	std::string astr2{ "another test string" };
	auto m = get_message(form, astr1.c_str(), astr2.c_str());
	EXPECT_STREQ(m.c_str(), "Format test a test string follows another test string.");
}

TEST(Testing_get_message, Mix)
{
	const char* form = "Format test %i + %i = %s.";
	int i{ 5 };
	int j{ 6 };
	std::string astr{ "eleven" };
	auto m = get_message(form, i, j, astr.c_str());
	EXPECT_STREQ(m.c_str(), "Format test 5 + 6 = eleven.");
}

TEST(Testing_to_lower, String_Is_Empty)
{
	std::string str{ "" };
	auto m = to_lower(str);
	EXPECT_STREQ(m.c_str(), "");
}

TEST(Testing_to_lower, Mixed_String)
{
	std::string str{ "a StRiNg TeSt; It TaKeS 30 mInUtEs To RuN." };
	auto m = to_lower(str);
	EXPECT_STREQ(m.c_str(), "a string test; it takes 30 minutes to run.");
}

TEST(Testing_to_upper, String_Is_Empty)
{
	std::string str{ "" };
	auto m = to_upper(str);
	EXPECT_STREQ(m.c_str(), "");
}

TEST(Testing_to_upper, Mixed_String)
{
	std::string str{ "a StRiNg TeSt; It TaKeS 30 mInUtEs To RuN." };
	auto m = to_upper(str);
	EXPECT_STREQ(m.c_str(), "A STRING TEST; IT TAKES 30 MINUTES TO RUN.");
}

// TODO str_to_wstr tests

//int main(int argc, char** argv)
//{
//	::testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TESTS();
//}
