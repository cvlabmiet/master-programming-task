/* Variant classes.
 * @file
 * @date 2018-08-12
 * @author Anonymous
 */

#ifndef __VARIANT_HPP__
#define __VARIANT_HPP__

#include <map>
#include <memory>
#include <variant>
#include <vector>

#include <boost/variant.hpp>

//{ number
using number = ...;
//}

//{ array
using array = ...;
//}

//{ recursive_array
struct recursive_array
{

};
//}

//{ recursive_array2
struct recursive_array2
{

};
//}

//{ variant_decorator
template<???>
struct variant_decorator
{
    ?? as() const
    {

    }

    ?? as()
    {
        return ??as()??;
    }
};
//}

//{ recursive_map
struct recursive_map
{

};
//}

#endif // __VARIANT_HPP__
