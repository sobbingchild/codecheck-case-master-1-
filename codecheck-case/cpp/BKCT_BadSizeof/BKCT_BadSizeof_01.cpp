// defect:bkcheck(BadSizeof)

// 案例1：param_not_really_an_array 从语法上看像是数组，但实际上是一个指针。
// 当您将 sizeof 运算符应用到指针后，会生成指针的大小（通常是 4 或 8 字节），
// 而不是预期的 10 字节
void bad_01(char param_not_really_an_array[10]) {
    // bad
    memset(param_not_really_an_array, 0, sizeof(param_not_really_an_array));
}

// 案例2：sizeof 被应用到了 this 指针而不是 *this 对象，这会产生不正确的对象大小值
size_t SomeClass::getObjectSize() const {
    // bad
    return sizeof(this);
}

// 案例3：sizeof 运算符被应用到了 s 的地址而不是 s 本身，这会产生较大的值并重写相邻的内存位置：
void bad_03() {
    short s;
    // bad
    memset(&s, 0, sizeof(&s));
}

// 案例4：sizeof 运算符被应用到了指针算术运算表达式 buf – 3。该表达式具有类型 char*，
// 而且大小可能是 4 或 8 字节，而不是将 sizeof 应用到 buf，然后从结果中减去 3，从而得出需要的值 97
void bad_04() {
    char buf[100];
    buf[0] = 'x';
    buf[1] = 'y';
    buf[2] = 'z';
    // bad
    memset(buf + 3, 0, sizeof(buf - 3));
}