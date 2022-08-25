/* Test file for quoted_string.
 * @file
 * @date 2018-08-18
 * @author Anonymous
 */

#include <catch2/catch_all.hpp>

#include <parser.hpp>
#include <quoted_string.hpp>

namespace
{
    std::string loads(const std::string& s)
    {
        return json::load_from_string<std::string>(s, json::parser::quoted_string);
    }
}

TEST_CASE("quoted_string::spaces")
{
    auto i = loads(R"#(" text with spaces ")#");
    CHECK(i == " text with spaces ");
}

TEST_CASE("quoted_string::comma")
{
    auto i = loads(R"#("abc comma (,)")#");
    CHECK(i == R"(abc comma (,))");
}

TEST_CASE("quoted_string::quote")
{
    auto i = loads(R"#("text with \"quote\"")#");
    CHECK(i == R"(text with "quote")");
}

TEST_CASE("quoted_string::newline")
{
    std::string s = R"("text with
newlines
")";

    auto i = loads(s);
    CHECK(i == "text with\nnewlines\n");
}

TEST_CASE("quoted_string::failure")
{
    auto s = {
        "abc",
        R"("first quote only)",
        R"(some text and "quote")"
    };

    for (const auto& x : s)
        CHECK_THROWS_AS(loads(x), std::runtime_error);
}
