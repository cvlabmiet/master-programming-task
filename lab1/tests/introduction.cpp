/* Test file for introduction task.
 * @file
 * @date 2021-09-04
 * @author Anonymous
 */

#include <regex>

#include <catch2/catch_all.hpp>

#include <introduction.hpp>

TEST_CASE("introduction")
{
    introduction intr;
    static_assert(sizeof(intr) > 1);

    CHECK(std::regex_match(intr.name().data(), std::regex{R"([A-Z]\w+)"}));
    CHECK(std::regex_match(intr.surename().data(), std::regex{R"([A-Z]\w+)"}));
    CHECK(std::regex_match(intr.fullname(), std::regex{R"(\w+ \w+)"}));
    // Alternate form is CHECK_THAT(intr.fullname(), Catch::Matchers::Matches(R"(\w+ \w+)"));
}
