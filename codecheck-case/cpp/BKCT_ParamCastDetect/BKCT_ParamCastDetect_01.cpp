// defect:bkcheck(ParamCastDetect)

#include <iostream>
#include <string>

void foo(std::string str) {
    std::cout << "The string is: " << str << std::endl;
}

int bad_01() {
    int num = 0;
    foo(num); // 这将导致编译错误，因为类型不匹配，编译错误不符合bkcheck的语义分析，现在不会给出告警了
    // bad
    foo(0); // 发生隐式转换导致未定义行为
    // bad
    foo(0l); // 发生隐式转换导致未定义行为
    return 0;
}

int bad_02() {
    long num = 0;
    foo(num); // 这将导致编译错误，因为类型不匹配，编译错误不符合bkcheck的语义分析，现在不会给出告警了
    // bad
    foo(0L); // 发生隐式转换导致未定义行为
    // bad
    foo(0x0); // 发生隐式转换导致未定义行为
    return 0;
}