// defect:bkcheck(ConstantExpression)

int bad(int a, int b) {
    // bad 条件恒真
    if (a == b ? 1 : 2) {

    }
    // bad 条件恒真
    if (true) {

    }
    // bad 条件恒假
    while (0) {

    }
    // bad 返回结果为常量
    return a > b ? 1 : 1;
}