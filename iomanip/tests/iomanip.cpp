/* Test file for iomanip task.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#include <catch.hpp>
#include <sstream>
#include <string>
#include <type_traits>

#include <iomanip.hpp>

TEST_CASE("iomanip::simple")
{
    std::stringstream s;
    s << "some text" << endm;
    CHECK(s.str() == "some text[eol]\n");
}

TEST_CASE("iomanip::one_operand")
{
    std::stringstream s;
    static_assert(!std::is_same_v<decltype(s << squares), std::ostream&>);
    s << "some test " << squares << 123 << " and " << squares << "me" << squares << -88.59;
    CHECK(s.str() == "some test [123] and [me][-88.59]");
}

TEST_CASE("iomanip::two_operands")
{
    std::stringstream s;
    static_assert(!std::is_same_v<decltype(s << add), std::ostream&>);
    static_assert(!std::is_same_v<decltype(s << add << 48), std::ostream&>);
    static_assert(std::is_same_v<decltype(s << add << 48 << 56), std::ostream&>);

    SECTION("int")
    {
        s << add << 124 << 589 << " == " << 713;
        CHECK(s.str() == "713 == 713");
    }

    SECTION("string")
    {
        using namespace std::literals;
        s << add << "abc"s << "efg"s << " text";
        CHECK(s.str() == "abcefg text");
    }

    SECTION("double")
    {
        s << "get => " << add << 45.89 << 32.177 << " <=";
        CHECK(s.str() == "get => 78.067 <=");
    }
}
