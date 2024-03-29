/* Strided range.
 * @file
 * @date 2021-12-17
 * @author Anonymous
 */

#ifndef __STRIDED_RANGE_HPP__
#define __STRIDED_RANGE_HPP__

#include <stdexcept>

#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/indexed.hpp>
#include <boost/range/adaptor/transformed.hpp>

template<class Range>
auto make_strided_range(Range& rng, size_t width, size_t stride)
{
    if (stride == 0)
        throw std::invalid_argument("stride != 0");

    using namespace boost::adaptors;
    const auto strided = [width, stride](const auto& x) { return x.index() % stride < width; };
    const auto valued = [](const auto& x) { return x.value(); };
    return rng | indexed() | filtered(strided) | transformed(valued);
}

#endif // __STRIDED_RANGE_HPP__
