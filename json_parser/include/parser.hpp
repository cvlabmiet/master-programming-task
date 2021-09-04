/* Helper load functions to parse into object.
 * @file
 * @date 2018-08-18
 * @author Anonymous
 */

#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <boost/spirit/home/x3.hpp>

#include <string>

namespace parser
{
    template<class Difference>
    class iterator_exhausted: public std::range_error
    {
    public:
        iterator_exhausted(Difference diff):
            range_error("Trailing symbols, difference: " + std::to_string(diff)),
            diff_(diff)
        {}

        Difference get_difference() const
        {
            return diff_;
        }

    private:
        Difference diff_;
    };

    template<class Result, class Iterator, class Grammar>
    constexpr auto load(Iterator first, Iterator last, const Grammar& gr)
    {
        namespace x3 = boost::spirit::x3;
        Result result;
        if (!x3::phrase_parse(first, last, gr, x3::ascii::space, result))
            throw std::runtime_error("Invalid input data");

        if (first != last)
            throw iterator_exhausted(std::distance(first, last));

        return result;
    }

    template<class Result, class Grammar>
    constexpr auto load_from_string(const std::string& message, const Grammar& gr)
    {
        return load<Result>(message.begin(), message.end(), gr);
    }
}

#endif // __PARSER_HPP__
