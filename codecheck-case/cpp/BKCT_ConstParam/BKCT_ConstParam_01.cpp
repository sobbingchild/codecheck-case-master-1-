// defect:bkcheck(ConstParam)

// good:函数入参推荐使用 const 修饰
int good(const int &num1, const int &num2) {
    return num1 + num2;
}

// bad:函数入参没有使用 const 修饰
int bad_01(int &num1, int &num2) {
    return num1 + num2;
}

// bad:函数入参没有使用 const 修饰
int bad_02(const int &num1, int &num2) {
    return num1 + num2;
}

// bad:函数入参没有使用 const 修饰
int bad_03(int &num1, const int &num2) {
    return num1 + num2;
}

// bad:函数入参没有使用 const 修饰
int bad_04(int &num1) {
    return num1;
}
