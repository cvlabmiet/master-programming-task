/* Test file for parser task.
 * @file
 * @date 2018-08-09
 * @author Anonymous
 */

#include <catch2/catch_all.hpp>

#include <variant>

#include <json.hpp>

#include "parser.hpp"

TEST_CASE("json::number")
{
    std::string s = "123,5654, 87, 9, -22.58";
    auto i = json::load_from_string<std::vector<std::variant<float, int>>>(s, json::parser::number % ',');

    CHECK(std::get<int>(i[0]) == 123);
    CHECK(std::get<int>(i[1]) == 5654);
    CHECK(std::get<int>(i[2]) == 87);
    CHECK(std::get<int>(i[3]) == 9);
    CHECK(std::get<float>(i[4]) == Catch::Approx(-22.58f));
}

TEST_CASE("json::nullable")
{
    auto i = json::load_from_string<nullptr_t>("null", json::parser::nullable);
    CHECK(i == nullptr);
}

TEST_CASE("json::array")
{
    SECTION("the same type")
    {
        auto i = json::load_from_string<json::types::array>("[1, 2, 3]", json::parser::array);
        CHECK(boost::get<int>(i[0]) == 1);
        CHECK(boost::get<int>(i[1]) == 2);
        CHECK(boost::get<int>(i[2]) == 3);
    }

    SECTION("different types")
    {
        auto i = json::load_from_string<json::types::array>(R"([ "abc", "er", 123, -58.2, null, false ])", json::parser::array);
        CHECK(boost::get<std::string>(i[0]) == "abc");
        CHECK(boost::get<std::string>(i[1]) == "er");
        CHECK(boost::get<int>(i[2]) == 123);
        CHECK(boost::get<float>(i[3]) == Catch::Approx(-58.2f));
        CHECK(boost::get<nullptr_t>(i[4]) == nullptr);
        CHECK(boost::get<bool>(i[5]) == false);
    }

    SECTION("self type")
    {
        auto i = json::load_from_string<json::types::array>(R"([[1, 2], ["some", false, -2.5], null, "abc"])", json::parser::array);

        auto& sub0 = boost::get<x3::forward_ast<json::types::array>>(i[0]).get();
        CHECK(boost::get<int>(sub0[0]) == 1);
        CHECK(boost::get<int>(sub0[1]) == 2);

        auto& sub1 = boost::get<x3::forward_ast<json::types::array>>(i[1]).get();
        CHECK(boost::get<std::string>(sub1[0]) == "some");
        CHECK(boost::get<bool>(sub1[1]) == false);
        CHECK(boost::get<float>(sub1[2]) == Catch::Approx(-2.5f));

        CHECK(boost::get<nullptr_t>(i[2]) == nullptr);
        CHECK(boost::get<std::string>(i[3]) == "abc");
    }
}

TEST_CASE("json::object")
{
    SECTION("different types")
    {
        auto s = R"({ "number": 99, "string": "text", "boolean": true, "null": null, "array":[1,2,3] })";
        auto i = json::load_from_string<json::types::object>(s, json::parser::object);
        CHECK(boost::get<int>(i["number"]) == 99);
        CHECK(boost::get<std::string>(i["string"]) == "text");
        CHECK(boost::get<bool>(i["boolean"]) == true);
        CHECK(boost::get<nullptr_t>(i["null"]) == nullptr);

        auto& subarray = boost::get<x3::forward_ast<json::types::array>>(i["array"]).get();
        CHECK(boost::get<int>(subarray[0]) == 1);
        CHECK(boost::get<int>(subarray[1]) == 2);
        CHECK(boost::get<int>(subarray[2]) == 3);
    }

    SECTION("recursion")
    {
        auto s = R"({"nest": {"val": 7, "next":{"key": 87, "val": true}}, "end": false})";
        auto i = json::load_from_string<json::types::object>(s, json::parser::object);

        CHECK(boost::get<bool>(i["end"]) == false);
        auto& sub = boost::get<x3::forward_ast<json::types::object>>(i["nest"]).get();
        CHECK(boost::get<int>(sub["val"]) == 7);

        auto& subsub = boost::get<x3::forward_ast<json::types::object>>(sub["next"]).get();
        CHECK(boost::get<int>(subsub["key"]) == 87);
        CHECK(boost::get<bool>(subsub["val"]) == true);
    }
}

TEST_CASE("json::json")
{
    SECTION("root is object")
    {
        auto s = R"({"message": "text", "val": 123})";
        auto i = json::load_from_string<json::types::json>(s, json::parser::json);
        auto& obj = boost::get<json::types::object>(i);
        CHECK(boost::get<std::string>(obj["message"]) == "text");
        CHECK(boost::get<int>(obj["val"]) == 123);
    }

    SECTION("root is array")
    {
        auto s = R"(["text", 13, false])";
        auto i = json::load_from_string<json::types::json>(s, json::parser::json);
        auto& arr = boost::get<json::types::array>(i);
        CHECK(boost::get<std::string>(arr[0]) == "text");
        CHECK(boost::get<int>(arr[1]) == 13);
        CHECK(boost::get<bool>(arr[2]) == false);
    }
}
