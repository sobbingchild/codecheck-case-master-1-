// defect:bkcheck(DevideByZero)

void bad_01() {
    int a = 0;
    // bad
    int b = 1 / a;
}

void bad_02() {
    // bad
    int b = 1 / 0;
}

void bad_03() {
    double x = 1.0;
    double y = 0.0;
    // bad
    double z = x / y; // 除0错误，因为y等于0(本case暂时不报，不包含double类型)
}

void bad_04() {
    int a = 0, b = 1;
    // bad
    b /= a;
}

void bad_05() {
    int *p = nullptr;
    int x = 10;
    // bad
    int z = x / p; // 除0错误，因为p是空指针
}