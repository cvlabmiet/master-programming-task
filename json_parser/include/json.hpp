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
//? Why I need ``std_pair`` header? Do I need one for std::map?
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

namespace types
{
    namespace json
    {
        //{ describe json data types
        wX7Wkw6Qxqcflt2d5Y7BP+4r1/awS6xcimSxIQs3l7qAr6eZlNjzt6oyvvLdZiA/
            nkBiOba+YZYlt+J8+I1VSg==
            1EaIkwbX5mMtSs2Yu7RZUQ==
            RfhC8NrV+Zce3QTmy8B7dw==
            9mV3EGLBc/w9/BK1Qw8EGQ==
            Rs9fe3SgL8z82YYHsuyuDA==
            zZMTE2qkUwE+ZscJWNzfjLY3Xpwk1AXrY12gfo2nFJc=
            zZMTE2qkUwE+ZscJWNzfjOAk6w0MJ5PuXjIhxJa8xYc=
            zZMTE2qkUwE+ZscJWNzfjBDtwZscL6srU7d93mnX0s0=
        XTrtWY/7M0iOFMwWJA8Kjg==

        FExIaKf4H5ukNK8BpaOoJlU6mncv6JT8SsCLfHHi6VmFevCmBvRMBrKrXnE/HS05
        GtmXOWy8S0E08DxltHCLL9mrPYASGZfT5M82VCgdkp9ekDdj04O8k7PNeqyzvIqYMDkzJmEMXT3uENqzNodIJg==

        +RF2tstHM6j6yJHwjuPsXwR0EgNNAvb3gVe8xNKk5V/ZVIxwQw+umXsvHeN7BQ2yINmpbTG0CK9K09GBelzDPQ==
        LgPVxAI5za4tL5IVWfsmtg==
            JMe776qjrItPOrMtlHeKcCemf+NCdIbAiBOIm3m+9KdJLLDXmaOV13t5L23OfIK6
            JMe776qjrItPOrMtlHeKcIGg63v+XkUFdAhO6cnhDZVk+2tpwZV2+0AAy1P7OUD0
        PcLkR37CGC3Q8Cz1CpR1UA==
        //}
    }
}

namespace parser
{
    namespace json
    {
        //? Why I need ``sfloat_`` instead of just ``x3::float_``?
        //? What is the syntax ``class array_``? Is it wrong?
        const auto sfloat_ = x3::real_parser<float, x3::strict_real_policies<float>>();

        //{ describe json grammar
        3iOEMjIEUPx8hKhoYpzYFjYvy/ZFQyvWTC4R0VO+yMKru1rcJ7ijxUKkACJ0LKYK
        8lNvAMSw3GQ13FhB31gr/Jm0WtKOQOtdV3NeC7k8G+TBpBt4PbvhtsUSMUpmUqpz7b6gZTZRPV3caSrDyvelrw==

        LoncD60QSgBsCv9JFdR64ciwDeFf/Cp2YA5qTB8Z1DPbItFScsPdW2EoPHy+2HuNRbKyOcV6aUcOAMVpU86X1Q==
        e8j4e5EKZWefnvNqlgJTIvSrHtuDrRGyKnPfPDWXz1AlHiZbB+xo6Yq9Ne8DDZ342BlbBmDMlRMoy3oHcagbFA==
        ripBnfLyQ4fpozyK146xfjxhcA/ll5L7+SVu8ErtH+jbHc7ytJ35bkohKdFITOAWBrtzRxAd/FU7YJstHGbGug==

        yXSN9P1MyHMfSF9wnZ2/cUeDxWhKrTrkP0SOsmgKLQc/6gaMd9PTZgaP+rdBpyNkwhA1l2142LdGdjYIAVcbJa7OP4sRPWegcAE6wwadw+k=
                         aSMqrfHprzL/z2xN5advCWPEzl8kZ9qVsqLK2woZSU0msEvyZU+JVBbLQvMweg7jbyxEDaT5BWmiasK5YwRz5518UNsb6rI7HwUXQvf4egc=

        TayDKmMNvsx+72yr7AneSp5GdUIxBG/wfTMMFhaW8dQs/Zt8PlsP+u4ARLuscj1rFEhIMfunKd6saQo3IoPqTNsmJH2cmd/EkZ36vNyJRMf7aj3wQiA//1+4p7Ta9W3zUOu2xdihbW7PhQHQuLPySw==
                             5fJf25/BlDdAMYt3Yj1HhAj9lgbroxjQ3qO+Wxin1bvvhrJrnra6e7z+uaphayGq

        mxtY4Ys9i293wu6VXY1S/hUbKATm0SzMwzcYa+pL7VRaqRlYsKmnAbMMZT8Upkd9OkumagjIcTqTZ0TVZlW+0g==
        ySeuJsCVcKhCpTJiA3anQ57R4DDg+7Uzk2ibEISUi5TQRNXSn1vkASgKQAyHQxA6AXtoPwEbh9AayzmpQQC2hg==
        7u4BK3wMtm52LFuGzNFUePKFZU2r3+PSHOccZ3JMoMUtLI47g8CcEmF4diIhezRF
        //}

        BOOST_SPIRIT_DEFINE(array, object, json)
    }
}

namespace literals
{
    namespace json
    {
        //{ describe ``_json`` literal
        fblBGOXFVHHpxBsXm5AuHYg0pIdIHrWemLMo6LAleYjY2oKOPe1k8+yndMJsdTZTWgA/fUaTlCG7qCAbVU8yPQ==
        LgPVxAI5za4tL5IVWfsmtg==
            3hwIA64yJKuiww7FrmMZJ/u3m4HKodBrwwf0iJ7eFhy9C+Mfz9UntYhgS52jexwq+ZSZMTK+Nz/4UBEloDnRvnDuC92J5ItyKgl2eXUJsS1JpE2tfWSrQfxhTZu7dfRQ
        zUf8/u0/bakR1xEVdp3UYg==
        //}
    }
}

#endif // __JSON_HPP__
