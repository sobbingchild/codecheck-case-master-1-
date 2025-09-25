// defect:bkcheck(PointerInit)
#include <iostream>
#include <tuple>

void bad_01() {
    int a;
    // bad
    int b = a + 1;
}

void bad_02() {
    int *a;
    // bad
    int b = *a + 1;
}

void bad_03(int i) {
    int *a;
    if (i > 0) {
        a = new int[5];
    }
    // bad
    int b = *a + 1;
}

void bad_04(int i) {
    int a;
    if (i > 0) {
        a = 5;
    }
    // bad
    int b = a + 1;
}

// 一个返回两个整数的函数
std::tuple<int, int> get_two_ints() {
    return std::make_tuple(1, 2);
}

int good() {
    int a, b;
    // 使用std::tie解包元组，将值赋给a和b
    std::tie(a, b) = get_two_ints();
    // good
    std::cout << "a: " << a << ", b: " << b << std::endl;
    //auto [a, b] = get_two_ints();
    return 0;
}