#include <cstdint>
#include <string>
class Base1;
//
// Created by wadema on 24-7-2.
//
// define:bkcheck(ReturnType)


long good_01()
{
    // good
    return 0;
}

double good_02()
{
    // good
    return 0;
}

Base1* good_03()
{
    // good
    return 0;
}

size_t good_04(int a)
{
    if (a > 0)
    {
        // bad
        return a;
    }
    uint32_t b = 5;
    // good
    return b;
}

int64_t good_05(long long a)
{
    if (a > 0)
    {
        // good
        return a;
    }
    long long int b = 5;
    // good
    return b;
}

// T 为模板类型，可以认为和各类型都匹配
T good_06(long long a)
{
    if (a > 0)
    {
        // good
        return a;
    }
    long long int b = 5;
    // good
    return b;
}

T getT();

int good_07(T a)
{
    if (a > 0)
    {
        // good
        return getT();
    }
    // good
    return a;
}
