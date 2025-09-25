//
// Created by wadema on 24-7-12.
//
// define:bkcheck(MemsetParam)

#include <string.h>

void bad()
{
    // 错误示例：
    struct A{
        int x;
        int y;
    };
    struct B{
        int x;
        int y;
    };
    A a{};
    B b{};
    // bad
    memset(&a, 0, sizeof(b));
    // bad
    memset(&a, 0, sizeof(&a)); // 注意这两种是类形不匹配
}


void good_01()
{
    struct Test{
        int x;
        int y;
    };
    Test A{};
    // good
    memset(&A, 0, sizeof(Test)); // 也是合法的u
}

void good_02()
{
    //正确示例：
    struct A{
        int x;
        int y;
    };
    struct B{
        int x;
        int y;
    };
    A a{};
    B b{};
    // good
    memset(&a, 0, sizeof(a));
}
