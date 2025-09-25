// defect:bkcheck(DontUseBool)

void foo(bool flag) {

}

void bar(int a, bool flag) {

}

void bad_01() {
    // bad:使用bool类型作为函数参数，给出告警
    foo(true);
    bool flag = false;
    // bad:使用bool类型作为函数参数，给出告警
    foo(flag);
}

void bad_02() {
    // bad:使用bool类型作为函数参数，给出告警
    bar(1, true);
    bool flag = false;
    // bad:使用bool类型作为函数参数，给出告警
    bar(2, flag);
}