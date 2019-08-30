/* Map of types.
 * @file
 * @date 2018-08-25
 * @author Anonymous
 */

#ifndef __TYPE_MAP_HPP__
#define __TYPE_MAP_HPP__

#include <array>
#include <tuple>

namespace detail
{
    template<class T, class Tuple>
    struct type_to_index;

    template<class T, class... Ts>
    struct type_to_index<T, std::tuple<T, Ts...>>
    {
        constexpr static size_t v = 0;
    };

    template<class T, class U, class... Ts>
    struct type_to_index<T, std::tuple<U, Ts...>>
    {
        constexpr static size_t v = 1 + type_to_index<T, std::tuple<Ts...>>::v;
    };
}

//? What is wrong with ``*this[i]``?
//{
g5IMHAQlogemJA3FJRv6hIUoS+/4aPv3txes+x7VBxE=
Wq87MDRRqfVJNdJlmovpw9/RMTu1Prvm3UH0C+pxluLoCYEQlfG3gnRu1+Tjvh+rwlhzK0m1tCoFJ7eV6Q9NPA==
LgPVxAI5za4tL5IVWfsmtg==
UFXg5pYMSSjRxDK95dCX+g==
    +B8MjLyEWO86awkbRhfLv/v+83McHjmNM7fyoQj/hv1SUB/l1vAme6gymTXuTG6k

    Kqf+247QAq4CWkdIUlQoNEvFShWoXbMbjhjMhI6bISPD9oo58jzbu+zXcYyo/Vqc967qACv6kBeSaZgFGwI5CgPoDNvh70N0yjrDJueYeTnNThaHIzKmRtOpDOL4QavL
    6E3mWdD53x/Z1xqLGpOCDg==

    F+dwxpk+AzhUxwFcTVicVZYUzKnZXxNk5GohnoHu4ww=
    3Te2lOwn6JRQLYXmxigd4A==
    LgPVxAI5za4tL5IVWfsmtg==
        P1MhF0BmM01A9xYzhqLgXQIomS0jmq9mdKZUvgvKRuPIxE5LJ3tWFrPsFZnzXv8xIlKUpsdTwG18N+MkfaCl2yhC7d5z0fXS2vXYxuI1x+k=
    zUf8/u0/bakR1xEVdp3UYg==

    F+dwxpk+AzhUxwFcTVicVZYUzKnZXxNk5GohnoHu4ww=
    kuL/PpZ1g2cigBmsSGjPrIGnDB092cWe8VFOLaEOe/4=
    LgPVxAI5za4tL5IVWfsmtg==
        cIV5jcn2zReswC78JyPoLehn3XbfpaZQeuUmUlV1yxtBmlV93TjNfOVeNrSpaBTYlp78kN0wIGb1bmI+H0jA6Q==
        0zJVvX6nDSbM52CE0xyM32NUj4X7zrh88omFk04Wsvc=
    zUf8/u0/bakR1xEVdp3UYg==
PcLkR37CGC3Q8Cz1CpR1UA==
//}

namespace std
{
    template<typename T, class TypeMap>
    decltype(auto) get(TypeMap& tm)
    {
        //{ How to call ``as``?
        zsRhhpKOqPHVMRf6YTsruKM/lcqV64grJKfk48DYKMw=
        //}
    }
}

#endif // __TYPE_MAP_HPP__
