/* Test file for iterator task.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#include <algorithm>
#include <numeric>
#include <vector>

#include <catch2/catch.hpp>

#include <iterator.hpp>

namespace
{

template<class Container = std::vector<uint8_t>>
class image
{
public:
    image(size_t width, size_t height, size_t stride):
        data(stride * height),
        width_(width),
        stride_(stride)
    {}

    auto begin()
    {
        return image_iterator(data.begin(), width_, stride_);
    }

    auto end()
    {
        return image_iterator(data.end(), width_, stride_);
    }

    auto begin() const
    {
        return image_iterator(data.begin(), width_, stride_);
    }

    auto end() const
    {
        return image_iterator(data.end(), width_, stride_);
    }

private:
    Container data; // image data including strides. Access by (x, y): data[y * stride_ + x]
    size_t width_;
    size_t stride_;
};

} // namespace

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
        CHECK(std::distance(myimage.begin(), it) == 120);
        it -= 50;
        CHECK(std::distance(myimage.begin(), it) == 70);
    }

    SECTION("advance: delta > width")
    {
        it += 130;
        CHECK(std::distance(myimage.begin(), it) == 130);
        it -= 50;
        CHECK(std::distance(myimage.begin(), it) == 80);
        it += 289;
        CHECK(std::distance(myimage.begin(), it) == 369);
    }

    SECTION("distance")
    {
        CHECK(std::distance(it, myimage.end()) == length);
        it += length / 3 + 17;
        CHECK(std::distance(myimage.begin(), it) == length / 3 + 17);
        CHECK(std::distance(it, myimage.end()) == length - (length / 3 + 17));
    }

    SECTION("next row")
    {
        CHECK(std::distance(it + 127, it + 128) == 1);
        CHECK(std::distance(it + 128, it + 127) == -1);
    }

    SECTION("prev row")
    {
        CHECK(std::distance(myimage.begin() - 1, myimage.begin()) == 1);
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
    std::iota(v.begin(), v.end(), 73);

    copy(v.begin(), v.end(), im1.begin());
    CHECK(std::equal(im1.begin(), im1.end(), v.begin(), v.end()));
}

TEST_CASE("iterator::copy_to_vector")
{
    image im1(128, 4, 256);
    std::iota(im1.begin(), im1.end(), 42);

    std::vector<uint8_t> v(128 * 4);
    std::copy(im1.begin(), im1.end(), v.begin());

    CHECK(std::equal(im1.begin(), im1.end(), v.begin(), v.end()));
}

TEST_CASE("iterator::previous_from_end")
{
    image im(128, 4, 256);

    auto it = im.end();
    --it;
    CHECK(it == im.begin() + (128 * 4 - 1));
}

TEST_CASE("iterator::dont_touch_my_constructor")
{
    std::vector<int> v;
    image_iterator it(v.begin(), 0, 0);
    CHECK_NOTHROW(++it);
}

TEST_CASE("iterator::reject_advance_workaround")
{
    class custom_iterator : public boost::iterator_facade<custom_iterator, int, boost::random_access_traversal_tag>
    {
    public:
        void advance(int x)
        {
            if (x == 1)
                throw std::logic_error("operator++ in advance is prohibited");

            if (x == -1)
                throw std::logic_error("operator-- in advance is prohibited");
        }

        typename iterator_facade::difference_type distance_to(const custom_iterator& x) const
        {
            return i - x.i;
        }

        int i = 0;
    };

    custom_iterator cc{};
    image_iterator it(cc, 10, 15);
    CHECK_NOTHROW(it + 5);
    CHECK_NOTHROW(it - 44);
}
