// defect:bkcheck(NullProtect)

void test(int *ptr) {
    // do something
}

void test2(int i, int *ptr) {
    // do something
}

void bad_01() {
    // bad
    test(nullptr); // 使用nullptr作为函数参数
    // bad
    test(NULL); // 使用NULL作为函数参数
}

void bad_02() {
    // bad
    test2(1, nullptr); // 使用nullptr作为函数参数
    // bad
    test2(2, NULL); // 使用NULL作为函数参数
}