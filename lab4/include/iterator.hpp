/* Image iterator.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <cmath>
#include <iterator>
#include <type_traits>
#include <utility>

#include <boost/iterator/iterator_adaptor.hpp>

//{ image iterator
template<class Iterator>
class image_iterator: public boost::iterator_adaptor<...>
{
public:

private:
    friend class boost::iterator_core_access;

    void increment()
    {
        ...
    }

    void decrement()
    {
        ...
    }

    void advance(typename image_iterator::difference_type)
    {
        ...
    }

    typename image_iterator::difference_type distance_to(const image_iterator&) const
    {
        ...
    }

    ...
};
//}

#endif // __ITERATOR_HPP__
