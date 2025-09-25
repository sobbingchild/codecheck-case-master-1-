//
// Created by wadema on 24-7-12.
//
// define:bkcheck(MemsetNoNumber)

#define MAX_LEN 4
#include <string.h>

void bad()
{
    // 错误示例：
    struct A
    {
        int x;
        int y;
    };
    A a{};

    // bad
    memset(&a, 0, MAX_LEN);
    // bad
    memset(&a, 0, 4);
    // bad
    memset(&a, 0, sizeof(a) * 10);
}
