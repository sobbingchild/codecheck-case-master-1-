// defect:bkcheck(LocalAssignToGlobal)

#include <stdlib.h>

int *buf;

void bad_01(unsigned n) {
    int aux;
    if (n == 1) {
        // bad
        buf = &aux; // 将局部变量aux的地址赋给全局指针buf
    } else {
        buf = (int *) malloc(n * sizeof(int));
    }
}

void bad_02(unsigned n) {
    int aux;
    while (n > 5) {
        // bad
        buf = &aux; // 将局部变量aux的地址赋给全局指针buf
        n--;
    }
}

void bad_03(unsigned n) {
    int aux;
    try {
        // bad
        buf = &aux; // 将局部变量aux的地址赋给全局指针buf
    } catch (declaration) {

    }
}

void bad_04(unsigned n) {
    int aux;
    for (int i = 0; i < 5; ++i) {
        // bad
        buf = &aux; // 将局部变量aux的地址赋给全局指针buf
    }
}

void good_01() {
    // thread_local
    thread_local
    FiberEntity master_fiber_impl;
    // good
    buf = &master_fiber_impl; // 将thread_local变量地址赋给全局指针，不应该告警
}

void good_02() {
    // 静态局部变量
    static int counter = 0;
    // good
    buf = &counter; // 将静态局部变量地址赋给全局指针，不应该告警
}

void good_03(int counter) {
    // good
    buf = &counter; // 将入参变量地址赋给全局指针，不应该告警
}

void good_04(const Context &context) {
    // good
    buf = &context; // 将入参变量地址赋给全局指针，不应该告警
}