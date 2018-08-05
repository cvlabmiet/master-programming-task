/* Test file for iomanip task.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#include <catch.hpp>
#include <sstream>
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
    static_assert(!std::is_same<decltype(s << squares), std::ostream&>::value);
    s << "some test " << squares << 123 << " and " << 123;
    CHECK(s.str() == "some test [123] and 123");
}

TEST_CASE("iomanip::two_operands")
{
    std::stringstream s;
    s << add << 124 << 589 << " == " << 713;
    CHECK(s.str() == "713 == 713");
}
