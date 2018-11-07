/* Test file for type map.
 * @file
 * @date 2018-08-25
 * @author Anonymous
 */

#include <catch.hpp>
#include <cstdint>

#include <type_map.hpp>

TEST_CASE("type_map::int")
{
    type_map<int, int, float, uint8_t> m{{4, 86, -9}};

    SECTION("std::get")
    {
        CHECK(std::get<int>(m) == 4);
        CHECK(std::get<float>(m) == 86);
        CHECK(std::get<uint8_t>(m) == -9);
    }

    SECTION("as accessor")
    {
        CHECK(std::get<int>(m) == m.as<int>());
        CHECK(std::get<float>(m) == m.as<float>());
        CHECK(std::get<uint8_t>(m) == m.as<uint8_t>());
    }
}

TEST_CASE("type_map::enum")
{
    enum type_e { U8 = 0, I8, U16 = 10, I16, U32 = 20, I32, F32 = 30 };

    //? Is this form more robust? Why?
    //``type_map<type_e> m{let<uint8_t>(U8), let<int8_t>(I8), let<float>(F32), let<uint32_t>(U32)};``
    type_map<type_e, uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, float> m{{
        U8, I8, U16, I16, U32, I32, F32
    }};

    CHECK(std::get<int8_t>(m) == I8);
    CHECK(std::get<uint32_t>(m) == U32);
    CHECK(std::get<uint16_t>(m) == U16);
    CHECK(std::get<float>(m) == F32);
}

TEST_CASE("type_map::write")
{
    type_map<int, int, float, uint8_t> m{{1, 2, 3}};

    SECTION("std::get")
    {
        std::get<float>(m) = 42;
        CHECK(m.as<float>() == 42);
    }

    SECTION("as")
    {
        m.as<int>() = 43;
        CHECK(m.as<int>() == 43);
    }
}
