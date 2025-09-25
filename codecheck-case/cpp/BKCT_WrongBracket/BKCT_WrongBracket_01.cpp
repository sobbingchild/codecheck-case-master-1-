// defect:bkcheck(WrongBracket)

bool rTuple(int a, bool Error = true);

void bad_01() {
    // bad ')'
    if (rTuple(exp), false) {
        // 右括号放在错误的位置会同时导致两个错误：
        // 1) 调用“rTuple”函数时，“Error”参数将等于“true”，尽管程序员将其设置为“false”。
        // 2) 逗号运算符“,”返回右侧部分的值。这意味着 (rTuple(exp), false) 条件将始终为“假”
    }
}

void good() {
    // good
    if (rTuple(exp, false)) {}
}

bool test(int a, bool Error = true, int b = 1);

void bad_02() {
    // bad
    if (test(a, 0), 5) {}
    // bad
    if (test(a), false, 5) {}
    // bad
    while (test(a), false, 5) {}
}