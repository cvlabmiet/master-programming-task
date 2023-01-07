/* Test file for proxy task.
 * @file
 * @date 2018-08-07
 * @author Anonymous
 */

#include <catch2/catch_all.hpp>

#include <string>

#include <proxy.hpp>

namespace
{
// used for tests
struct my_struct
{
    int i;
    std::string s;
    float f;
};

struct global_mutex_mock
{
    static int counter;

    global_mutex_mock()
    {
        counter = 0;
    }

    void lock()
    {
        counter++;
    }

    void unlock()
    {
        counter--;
    }
};

int global_mutex_mock::counter = 0;

}

TEST_CASE("proxy::access")
{
    my_struct st{54, "la-la-la", -5863.21f};
    ptr_holder p(&st);

    static_assert(std::is_same<decltype(p.operator->()), ptr_holder<my_struct>::proxy>::value);

    CHECK(p->i == 54);
    CHECK(p->s == "la-la-la");
    CHECK(p->f == Catch::Approx(-5863.21));
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

TEST_CASE("proxy::local_injection")
{
    struct mutex_mock
    {
        int counter = 0;

        void lock()
        {
            counter++;
        }

        void unlock()
        {
            counter--;
        }
    } my_mutex{};

    {
        ptr_holder<int, mutex_mock>::proxy p(nullptr, my_mutex);
        CHECK(my_mutex.counter == 1);

        auto pointer = p.operator->();
        CHECK(my_mutex.counter == 1);
        CHECK(pointer == nullptr);

        ptr_holder<int, mutex_mock>::proxy p2(nullptr, my_mutex);
        CHECK(my_mutex.counter == 2);
    }

    CHECK(my_mutex.counter == 0);
}

TEST_CASE("proxy::global_injection")
{
    my_struct my{4456, "lala", -8.5};
    ptr_holder<my_struct, global_mutex_mock> p(&my);
    CHECK(global_mutex_mock::counter == 0);

    CHECK(p->i == 4456);
    CHECK(global_mutex_mock::counter == 0);

    {
        const auto& pp = p.operator->();
        CHECK(global_mutex_mock::counter == 1);
        CHECK(pp->f == Catch::Approx(-8.5));
        CHECK(global_mutex_mock::counter == 1);
    }
    CHECK(global_mutex_mock::counter == 0);
}
