/* Test file for variant task.
 * @file
 * @date 2018-08-12
 * @author Anonymous
 */

#include <catch.hpp>
#include <string>
#include <variant.hpp>

TEST_CASE("variant::number")
{
    number i = 123;
    number f = -569.6f;
    CHECK(std::get<int>(i) == 123);
    CHECK(std::get<float>(f) == Approx(-569.6f));
}

TEST_CASE("variant::array")
{
    array arr = {123, -59.6f, 8.53f, -8};
    CHECK(std::get<int>(arr[0]) == 123);
    CHECK(std::get<float>(arr[1]) == Approx(-59.6f));
    CHECK(std::get<float>(arr[2]) == Approx(8.53f));
    CHECK(std::get<int>(arr[3]) == -8);
}

TEST_CASE("variant::recursive_array")
{
    recursive_array arr = {1, 2.2f, std::shared_ptr<recursive_array>(new recursive_array{3, 7.9f, -8}), 9};
    CHECK(std::get<float>(std::get<number>(arr[1])) == Approx(2.2f));
    CHECK(std::get<int>(std::get<number>(std::get<std::shared_ptr<recursive_array>>(arr[2])->operator[](2))) == -8);
    CHECK(std::get<int>(std::get<number>(arr[3])) == 9);
}

TEST_CASE("variant::recursive_array2")
{
    recursive_array2 arr = {1.0f, 2, recursive_array2{7, 9.0f}};
    CHECK(std::get<int>(std::get<number>(arr[1])) == 2);
    CHECK(std::get<float>(std::get<number>(std::get<boost::recursive_wrapper<recursive_array2>>(arr[2]).get()[1])) == 9.0f);
}

TEST_CASE("variant::variant_decorator")
{
    variant_decorator<std::string, float, int> v{86};
    CHECK(std::get<int>(v) == 86);

    SECTION("content")
    {
        v = "text";
        CHECK(v.as<std::string>() == "text");

        v = 33.56f;
        CHECK(v.as<float>() == Approx(33.56f));
    }

    SECTION("const")
    {
        const auto cv = v;
        CHECK(cv.as<int>() == 86);
    }

    SECTION("mutable")
    {
        v.as<int>() = 53;
        CHECK(v.as<int>() == 53);
    }
}

TEST_CASE("variant::recursive_map")
{
    using namespace std::string_literals;

    recursive_map m = {
        {"abc", 132},
        {"next", "message"s},
        {"map", recursive_map{
            {"inner", true},
            {"num", 123},
        }}
    };

    SECTION("std::get")
    {
        CHECK(std::get<int>(m["abc"]) == 132);
        CHECK(std::get<std::string>(m["next"]) == "message");
        auto& inner = std::get<boost::recursive_wrapper<recursive_map>>(m["map"]).get();
        CHECK(std::get<bool>(inner["inner"]) == true);
        CHECK(std::get<int>(inner["num"]) == 123);
    }

    SECTION("as")
    {
        CHECK(m["abc"].as<int>() == 132);
        CHECK(m["next"].as<std::string>() == "message");
        auto& inner = m["map"].as<recursive_map>();
        CHECK(inner["inner"].as<bool>() == true);
        CHECK(inner["num"].as<int>() == 123);
    }
}
