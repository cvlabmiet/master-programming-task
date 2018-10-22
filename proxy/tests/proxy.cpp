/* Test file for proxy task.
 * @file
 * @date 2018-08-07
 * @author Anonymous
 */

#include <chrono>
#include <string>
#include <future>

#include <catch.hpp>
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

// used for tests
struct my_struct
{
    int i = 0;
    string s = "hello";
    float f = -1.0;

    template<class Duration>
    void sleep(Duration x) const
    {
        this_thread::sleep_for(x);
    }
};

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

    for (auto _ : boost::irange(0, 20))
    {
        //? Why I need ``std::promise`` here?
        std::promise<void> notifier;
        //? Why I don't use ``thr`` anywhere? How the innder thread will be released?
        auto thr = std::async([&p, &notifier]()
        {
            notifier.set_value();
            p->sleep(50ms);
        });
        notifier.get_future().get();

        auto start = chrono::high_resolution_clock::now();
        p->i = 75;
        auto end = chrono::high_resolution_clock::now();

        REQUIRE(end - start >= 50ms);
    }
}

TEST_CASE("proxy::primitive")
{
    int i = 7;
    ptr_holder p(&i);

    *(p.operator->().operator->()) = 99;

    CHECK(i == 99);
}
