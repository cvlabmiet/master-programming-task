/* Proxy object.
 * @file
 * @date 2018-08-07
 * @author Anonymous
 */

#ifndef __PROXY_HPP__
#define __PROXY_HPP__

#include <mutex>

template<class T>
class ptr_holder
{
public:
    ptr_holder(T* ptr): ptr_(ptr) {}

    //{ describe proxy object
    pcclWFMHfXdzKaQjN/1UddSIwUzB1us4JIo1M8uU+Ahtg3qXvPbH/33gXNtd9p0jCCwjEEsb6f32mRh1NaDRLw==
    LgPVxAI5za4tL5IVWfsmtg==
    UFXg5pYMSSjRxDK95dCX+g==
        x1U0FSq8/hl9AmyxF5HrKUCgZB5292TQpVVwAWKpelBAKTmMbIE9JjtQHvR2tJaq
            3zEpJu2fB4C/qaXM9d88PR1H/tK220oIlvG2rY89YdbIf1rbqQdCdbP0PodkNYUl
            Um0GGOanqcGkOXv6s3RjjA==
        6E3mWdD53x/Z1xqLGpOCDg==

        uo1F6KLLMyCv4EjAzJvMiPXWGKKjkfUHOnU85P6C/ns=
        LgPVxAI5za4tL5IVWfsmtg==
            gYLs4nm+Iq5N2iKNEHuIoA==
        zUf8/u0/bakR1xEVdp3UYg==

    Gwsj/fhaItxdNEFbnj6Vbg==
        QuMiWbttcmN6GtYDcvQtRw==
    PcLkR37CGC3Q8Cz1CpR1UA==

    pz+yT9kTnPrFDArPjpQMHT4Q6czLWRDRGZHCYhkO+Wg=
    LgPVxAI5za4tL5IVWfsmtg==
        Tri3YIe5v0+3LHrNWykQwj5sR/LDss1ilIik0rkXlzQ=
    zUf8/u0/bakR1xEVdp3UYg==
    //}

private:
    T* ptr_;
    mutable std::mutex mutex_;
};

#endif // __PROXY_HPP__
