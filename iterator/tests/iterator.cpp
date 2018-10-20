/* Test file for iterator task.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#include <catch.hpp>
#include <iterator.hpp>
#include <numeric>

using namespace std;

TEST_CASE("iterator::operations")
{
    image myimage(128, 45, 140);
    const size_t length = 128 * 45;

    SECTION("begin/end")
    {
        CHECK(myimage.begin() != myimage.end());
    }

    auto it = myimage.begin();

    SECTION("prefix")
    {
        for (size_t i = 0; i < length; ++i)
            ++it;
        CHECK(it == myimage.end());
    }

    SECTION("postfix")
    {
        for (size_t i = 0; i < length; ++i)
            it++;
        CHECK(it == myimage.end());
    }

    SECTION("advance::length")
    {
        it += length;
        CHECK(it == myimage.end());
    }

    SECTION("advance: delta < width")
    {
        it += 120;
        CHECK(distance(myimage.begin(), it) == 120);
        it -= 50;
        CHECK(distance(myimage.begin(), it) == 70);
    }

    SECTION("advance: delta > width")
    {
        it += 130;
        CHECK(distance(myimage.begin(), it) == 130);
        it -= 50;
        CHECK(distance(myimage.begin(), it) == 80);
        it += 289;
        CHECK(distance(myimage.begin(), it) == 369);
    }

    SECTION("distance")
    {
        CHECK(distance(it, myimage.end()) == length);
        it += length / 3 + 17;
        CHECK(distance(myimage.begin(), it) == length / 3 + 17);
        CHECK(distance(it, myimage.end()) == length - (length / 3 + 17));
    }

    SECTION("next row")
    {
        CHECK(distance(it + 127, it + 128) == 1);
    }
}

TEST_CASE("iterator::write")
{
    image im(128, 4, 128);
    auto it = im.begin();
    it[369] = 45;

    CHECK(*(im.begin() + 369) == 45);
}

TEST_CASE("iterator::copy_from_vector")
{
    image im1(128, 5, 256);
    std::vector<uint8_t> v(128 * 5);
    iota(v.begin(), v.end(), 73);

    copy(v.begin(), v.end(), im1.begin());
    CHECK(std::equal(im1.begin(), im1.end(), v.begin(), v.end()));
}

TEST_CASE("iterator::copy_to_vector")
{
    const image im1(128, 4, 256);
    std::vector<uint8_t> v(128 * 4);

    copy(im1.begin(), im1.end(), v.begin());
    CHECK(std::equal(im1.begin(), im1.end(), v.begin(), v.end()));
}
