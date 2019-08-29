/* Test file for CSV task.
 * @file
 * @date 2018-08-15
 * @author Anonymous
 */

#include <catch2/catch.hpp>

#include <csv.hpp>
#include <parser.hpp>

TEST_CASE("csv::string")
{
    auto i = parser::load_from_string<std::string>("text with spaces", parser::csv::string);
    CHECK(i == "text with spaces");
}

TEST_CASE("csv::cell")
{
    const auto loads = [](const auto& x)
    {
        return parser::load_from_string<std::string>(x, parser::csv::cell);
    };

    CHECK(loads("abc") == "abc");
    CHECK(loads("123") == "123");
    CHECK(loads("\" text with spaces \"") == " text with spaces ");
}

TEST_CASE("csv::row")
{
    auto i = parser::load_from_string<std::vector<std::string>>("abc,123,\"text spaces\"\n", parser::csv::row);
    CHECK(i[0] == "abc");
    CHECK(i[1] == "123");
    CHECK(i[2] == "text spaces");
}

TEST_CASE("csv::csv")
{
    auto s = R"(cell1,cell2,cell3
    miet,msu,mephi
    "with spaces","with,comma",123
    )";

    auto i = parser::load_from_string<types::csv::csv>(s, parser::csv::csv);
    CHECK(i[0] == std::vector<std::string>{"cell1", "cell2", "cell3"});
    CHECK(i[1] == std::vector<std::string>{"miet", "msu", "mephi"});
    CHECK(i[2][0] == "with spaces");
    CHECK(i[2][1] == "with,comma");
    CHECK(i[2][2] == "123");
}

TEST_CASE("csv::operator_csv")
{
    using namespace literals::csv;

    auto i = R"(header,h0,h1,h2
    line0,c0,c1,c2
    line1,m0,m1,m2
    )"_csv;

    CHECK(i[0] == std::vector<std::string>{"header", "h0", "h1", "h2"});
    CHECK(i[1] == std::vector<std::string>{"line0", "c0", "c1", "c2"});
    CHECK(i[2] == std::vector<std::string>{"line1", "m0", "m1", "m2"});
}
