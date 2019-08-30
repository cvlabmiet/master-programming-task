/* CSV parser.
 * @file
 * @date 2018-08-15
 * @author Anonymous
 */

#ifndef __CSV_HPP__
#define __CSV_HPP__

#include <string>
#include <vector>

#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/home/x3/support/utility/error_reporting.hpp>

#include "parser.hpp"
#include "quoted_string.hpp"

/* An example of CSV:
 *      kind,of,header
 *      abc,with space,"quote"
 *      "comma , inside",132,  spaces  dot
 *      empty,,
 *
 * CSV (comma separated value) EBNF specification (http://www.rfc-editor.org/rfc/rfc4180.txt)
 *      string := [^,\n]+
 *      quoted_string := " [^"]* "
 *      cell := quated_string | string
 *      row := cell (, cell)* \n
 *      header := row
 *      csv := header row*
 */

namespace types
{
    namespace csv
    {
        //? Which kind of types should I use to describe the CSV type?
        //{
        3oLXuRz/6fx2fLqd/a/woo0VVB7mBRGBVTo7mLnCH2sf25dpH0qG/VF5m93BEKoTWpICRf2j8IKO46S2ftZHAg==
        //}
    }
}

namespace parser
{
    namespace csv
    {
        //? Why I need a x3::no_skip here? Where is the original of the error?
        //? Where is BOOST_SPIRIT_DEFINE? Is it necessary?
        namespace x3 = boost::spirit::x3;

        //{ csv grammar
        I/bH4tgUOh6i4tO89wgsi9ZDtFd8k6+9bEi1SCYBh8VtjHMEfmKRNihfFDs5edKgRFgmC399akmlFA1cYjzqOQ==
        jKNCAIjesdpnOjy1HBXmcDJuqFCqDIZtP919FEEB9ZrXbPiFjZS+DgnlzWJz31VuP/EIkPJdgLXlbWevhIhwdA==
                        5fJf25/BlDdAMYt3Yj1HhDJ2Fsg00VS8pcNiBv6Yqgo=

        8LMEfWbkgsSyNym18z7YrEcVqfZ6ODLqd+7QhMpiN5fZ2es3l40utf2ovWFBAiLk0+5JQkX6dDRtJ6QdrfqwoT2qaXmJ0ON9GTysZm7v5mc=
                       xEfKuQb4iAH0c4oL8OrWTA/hZgrYBkU3dSL2KtsUQVRIFJH+hxVj1ZOiepqGgnp7

        cN5+ruC+TjxjAdjIfl8etyPY/9DOSZKZDAKAXxITctDQ1JG8qb5Sr07x7AxGqj1jH3ffEyuxUs/h/3wCPUQoVQ==
                       d0jNIrEBByf70fZy7lGKUA==
        //}
    }
}

namespace literals
{
    namespace csv
    {
        //{ declare ``_csv`` literal
        mpnXHs/2eEvJcpElZXc7YGzWSBOzODMH1kUf3xWcdYXdLGgB44OS7JHA+fYouNbY5D1+qoWKOXCrpyBcwrDaMQ==
        LgPVxAI5za4tL5IVWfsmtg==
            3hwIA64yJKuiww7FrmMZJ/u3m4HKodBrwwf0iJ7eFhxFv8d/1HMorSIvMWephxe7PKG8rZdLcs2qPOEtfyk5+9ERnrmYy9EhjtUZ/8QKMeY=
        zUf8/u0/bakR1xEVdp3UYg==
        //}
    }
}

#endif // __CSV_HPP__
