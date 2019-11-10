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

namespace
{
// used for tests
struct my_struct
{
    int i = 0;
    string s = "hello";
    float f = -1.0;

    void method1(std::future<void>& f, std::promise<void>& started)
    {
        started.set_value();
        f.wait_for(5s);
    }

    void method2(std::future<void>& f)
    {
        s = "world";
        f.wait_for(5s);
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

    for (auto _[[maybe_unused]] : boost::irange(0, 10))
    {
        p->s = "hello";

        //? Why I need 2 ``std::promise`` here?
        std::promise<void> started;
        std::promise<void> notifier;
        auto thr = std::async([&p, f = std::move(notifier.get_future()), &started]() mutable
        {
            p->method1(f, started);
        });

        started.get_future().get();

        std::promise<void> notifier2;
        auto thr2 = std::async([&p, f = std::move(notifier2.get_future())]() mutable
        {
            p->method2(f);
        });

        notifier2.set_value();
        CHECK(st.s == "hello");
        notifier.set_value();
    }
}

TEST_CASE("proxy::primitive")
{
    int i = 7;
    ptr_holder p(&i);

    *(p.operator->().operator->()) = 99;

    CHECK(i == 99);
}

TEST_CASE("proxy::const")
{
    int i = 45;
    const ptr_holder p(&i);
    const auto& pp = p.operator->();

    CHECK(*(pp.operator->()) == 45);
}
