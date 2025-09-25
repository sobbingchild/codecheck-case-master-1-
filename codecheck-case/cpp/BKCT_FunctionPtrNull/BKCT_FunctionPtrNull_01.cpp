//
// Created by wadema on 24-12-5.
//
#include <iostream>

void bad_case1()
{
    int (*funcPtr1)(int, int);
    void (*funcPtr)() = nullptr;
    void (*funcPtr2)();
    // bad
    funcPtr(); // 使用前没有判空
}

void bad_case2(void (*funcPtr)(), int (*operation)(int, int))
{
    // bad
    funcPtr(); // 使用前没有判空
}

void bad_case3()
{
    void (*funcPtr)(int) = nullptr;
    if (true)
    {
        // bad
        funcPtr(5); // 使用前没有判空
    }
}

void bad_case4(void (*funcPtr)())
{
    if (funcPtr != nullptr)
    {
        // Do something
    }
    // bad
    funcPtr(); // 在其它操作后没有再判空
}

void good_case1()
{
    void (*funcPtr)(int) = nullptr;
    if (funcPtr != nullptr)
    {
        // good
        funcPtr(5);
    }
}

void good_case2(void (*funcPtr)())
{
    if (funcPtr != nullptr)
    {
        // good
        funcPtr();
    }
}

void good_case3()
{
    void (*funcPtr)() = nullptr;
    if (funcPtr)
    {
        // good
        funcPtr();
    }
}

void good_case4(void (*funcPtr)())
{
    if (funcPtr == nullptr)
    {
        return; // 返回或处理错误情况
    }
    // good
    funcPtr();
}
