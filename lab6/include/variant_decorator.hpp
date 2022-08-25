/* Type decorator for variant.
 * @file
 * @date 2018-08-15
 * @author Anonymous
 */

#ifndef __VARIANT_DECORATOR_HPP__
#define __VARIANT_DECORATOR_HPP__

#include <boost/spirit/home/x3/support/ast/variant.hpp>

namespace x3 = boost::spirit::x3;

//{
template<???>
struct variant_decorator: public x3::variant<???>
{
    using ???operator=;
    using ...

    template<class T>
    T& as()
    {
        return ...
    }
};
//}

#endif // __VARIANT_DECORATOR_HPP__
