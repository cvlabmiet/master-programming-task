/* Type decorator for variant.
 * @file
 * @date 2018-08-15
 * @author Anonymous
 */

#ifndef __VARIANT_DECORATOR_HPP__
#define __VARIANT_DECORATOR_HPP__

#include <boost/spirit/home/x3/support/ast/variant.hpp>

namespace x3 = boost::spirit::x3;

//? How to inherit x3::variant constructor & ``operator=``?
//? Why I need inherited constructor & ``operator=``?
//? How many constructors did I inherit?
//? Do I need my own constructor & ``operator=``? Why?
//{
template<???>
struct variant_decorator: public x3::variant<???>
{
    using ???operator=;
    using ...

    //? Do I need a ``const``-version?
    template<class T>
    T& as()
    {
        return ...
    }
//}

#endif // __VARIANT_DECORATOR_HPP__
