/* Test file for proxy task.
 * @file
 * @date 2018-08-07
 * @author Anonymous
 */

#include <catch2/catch.hpp>

#include <chrono>
#include <string>
#include <future>

#include <proxy.hpp>

#include <boost/range/irange.hpp>

using namespace std;
using namespace std::chrono_literals;

namespace Catch
{
    // meta map<std::ratio type, std::string>
    template<class T> string ratio_to_string = "unk";
    template<> string ratio_to_string<std::nano> = "n";
    template<> string ratio_to_string<std::milli> = "m";
    template<> string ratio_to_string<std::ratio<1>> = "";

    // to output std::chrono::duration in failed CHECK, instead of "{?} == {?}"
    template<class R, class P>
    struct StringMaker<chrono::duration<R, P>>
    {
        static string convert(const chrono::duration<R, P>& value)
        {
            return to_string(value.count()) + ratio_to_string<P> + "s";
        }
    };
}

namespace
{
    // used for tests
    struct my_struct
    {
        int i = 0;
        string s = "hello";
        float f = -1.0;

        void method(std::future<void>& f)
        {
            f.wait_for(5s);
            s = "world";
        }
    };
}

TEST_CASE("proxy::access")
{
    my_struct st{54, "la-la-la", -5863.21f};
    ptr_holder p(&st);

    static_assert(std::is_same<decltype(p.operator->()), ptr_holder<my_struct>::proxy>::value);

    CHECK(p->i == 54);
    CHECK(p->s == "la-la-la");
    CHECK(p->f == Approx(-5863.21));
}

TEST_CASE("proxy::threadsafe")
{
    my_struct st;
    ptr_holder p(&st);

    for (auto _[[maybe_unused]] : boost::irange(0, 20))
    {
        p->s = "hello";

        //? Why I need 2 ``std::promise`` here?
        std::promise<void> start;
        std::promise<void> notifier;
        auto thr = std::async([&p, f = std::move(notifier.get_future()), &start]() mutable
        {
            start.set_value();
            p->method(f);
        });

        start.get_future().get(); // start has passed

        //? Why ptr_holder is not used here?
        CHECK(st.s == "hello");

        notifier.set_value();
        p->i = 75;

        //? What happens if I delete get()?
        thr.get();

        CHECK(p->i == 75);
        CHECK(p->s == "world");
    }
}

TEST_CASE("proxy::primitive")
{
    int i = 7;
    ptr_holder p(&i);

    *(p.operator->().operator->()) = 99;

    CHECK(i == 99);
}
