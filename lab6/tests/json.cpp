/* Test file for parser task.
 * @file
 * @date 2018-08-09
 * @author Anonymous
 */

#include <catch2/catch_all.hpp>

#include <variant>

#include <json.hpp>
#include <parser.hpp>

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
        CHECK(i[0].as<int>() == 1);
        CHECK(i[1].as<int>() == 2);
        CHECK(i[2].as<int>() == 3);
    }

    SECTION("different types")
    {
        auto i = json::load_from_string<json::types::array>(R"([ "abc", "er", 123, -58.2, null, false ])", json::parser::array);
        CHECK(i[0].as<std::string>() == "abc");
        CHECK(i[1].as<std::string>() == "er");
        CHECK(i[2].as<int>() == 123);
        CHECK(i[3].as<float>() == Catch::Approx(-58.2f));
        CHECK(i[4].as<nullptr_t>() == nullptr);
        CHECK(i[5].as<bool>() == false);
    }

    SECTION("self type")
    {
        auto i = json::load_from_string<json::types::array>(R"([[1, 2], ["some", false, -2.5], null, "abc"])", json::parser::array);

        auto& sub0 = i[0].as<json::types::array>();
        CHECK(sub0[0].as<int>() == 1);
        CHECK(sub0[1].as<int>() == 2);

        auto& sub1 = i[1].as<json::types::array>();
        CHECK(sub1[0].as<std::string>() == "some");
        CHECK(sub1[1].as<bool>() == false);
        CHECK(sub1[2].as<float>() == Catch::Approx(-2.5f));

        CHECK(i[2].as<nullptr_t>() == nullptr);
        CHECK(i[3].as<std::string>() == "abc");
    }
}

TEST_CASE("json::object")
{
    SECTION("different types")
    {
        auto s = R"({ "number": 99, "string": "text", "boolean": true, "null": null, "array":[1,2,3] })";
        auto i = json::load_from_string<json::types::object>(s, json::parser::object);
        CHECK(i["number"].as<int>() == 99);
        CHECK(i["string"].as<std::string>() == "text");
        CHECK(i["boolean"].as<bool>() == true);
        CHECK(i["null"].as<nullptr_t>() == nullptr);

        auto& subarray = i["array"].as<json::types::array>();
        CHECK(subarray[0].as<int>() == 1);
        CHECK(subarray[1].as<int>() == 2);
        CHECK(subarray[2].as<int>() == 3);
    }

    SECTION("recursion")
    {
        auto s = R"({"nest": {"val": 7, "next":{"key": 87, "val": true}}, "end": false})";
        auto i = json::load_from_string<json::types::object>(s, json::parser::object);

        CHECK(i["end"].as<bool>() == false);
        auto& sub = i["nest"].as<json::types::object>();
        CHECK(sub["val"].as<int>() == 7);

        auto& subsub = sub["next"].as<json::types::object>();
        CHECK(subsub["key"].as<int>() == 87);
        CHECK(subsub["val"].as<bool>() == true);
    }
}

TEST_CASE("json::json")
{
    SECTION("root is object")
    {
        auto s = R"({"message": "text", "val": 123})";
        auto i = json::load_from_string<json::types::json>(s, json::parser::json);
        auto& obj = i.as<json::types::object>();
        CHECK(obj["message"].as<std::string>() == "text");
        CHECK(obj["val"].as<int>() == 123);
    }

    SECTION("root is array")
    {
        auto s = R"(["text", 13, false])";
        auto i = json::load_from_string<json::types::json>(s, json::parser::json);
        auto& arr = i.as<json::types::array>();
        CHECK(arr[0].as<std::string>() == "text");
        CHECK(arr[1].as<int>() == 13);
        CHECK(arr[2].as<bool>() == false);
    }
}

TEST_CASE("json::operator_json")
{
    using namespace json::literals;

    auto i = R"({"text": "message", "number": 123})"_json;
    const auto& j = i.as<json::types::object>();
    CHECK(j.at("text").as<std::string>() == "message");
    CHECK(j.at("number").as<int>() == 123);
}
