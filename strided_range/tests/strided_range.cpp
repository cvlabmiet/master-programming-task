/* Test file for strided_range task.
 * @file
 * @date 2019-08-29
 * @author Anonymous
 */

#include <boost/range/iterator_range.hpp>
#include <vector>

#include <catch2/catch.hpp>

#include <strided_range.hpp>

// Two checks with different strides.
TEST_CASE("strided_range::stride")
{
}

// Two checks with different widths.
TEST_CASE("strided_range::width")
{
}

TEST_CASE("strided_range::stride_equal_width")
{
}

// Use boost::size.
TEST_CASE("strided_range::distance")
{
}

// Make strided_range from another strided_range.
TEST_CASE("strided_range::from_strided")
{
}

// Provide example with shifted data. It's like a window in the image. Hint: boost::make_iterator_range.
TEST_CASE("strided_range::shift")
{
}

TEST_CASE("strided_range::corner_case1")
{
}

TEST_CASE("strided_range::corner_case2")
{
}
