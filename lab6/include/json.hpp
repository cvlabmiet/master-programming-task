/* Json object.
 * @file
 * @date 2018-08-09
 * @author Anonymous
 */

#ifndef __JSON_HPP__
#define __JSON_HPP__

#include <map>
#include <string>
#include <vector>

#include <boost/spirit/home/x3.hpp>
#include <boost/fusion/adapted/std_pair.hpp>

#include "parser.hpp"
#include "quoted_string.hpp"
#include "variant_decorator.hpp"

/* Json EBNF specification (https://www.json.org)
 *      string := \" ([^\"] | \\\")* \"
 *      number := [0-9]+(\.[0-9]*)?
 *      boolean := "true" | "false"
 *      nullable := "null"
 *      value := number | string | boolean | nullable | array | object
 *      array := '[' value (',' value)* ']'
 *      key_value := string ':' value
 *      object := '{' key_value (',' key_value)* '}'
 *      json := array | object
 */

namespace json::types
{
    //{ describe json data types
    ... value = ...

    ... array
    ... object

    ... json
    //}
}

namespace json::parser
{
    const auto sfloat_ = x3::real_parser<float, x3::strict_real_policies<float>>();

    //{ describe json grammar
    ... number = ...
    ... nullable = ...

    ... array = ...
    ... object = ...
    ... json = ...

    ... value = ...

    ... key_value = ...

    ... array??? = ...
    ... object??? = ...
    ... json??? = ...
    //}

    BOOST_SPIRIT_DEFINE(array, object, json)
}

namespace json::literals
{
    //{ describe ``_json`` literal
    inline ... _json...
    {

    }
    //}
}

#endif // __JSON_HPP__
