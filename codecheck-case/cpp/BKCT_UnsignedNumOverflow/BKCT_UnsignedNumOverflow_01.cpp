//
// Created by wadema on 24-10-11.
//
// define:bkcheck(UnsignedNumOverflow)
void Test(int s)
{
    unsigned a, b, c, d, e = 0;
    b = 1;
    c = 2;
    // bad
    a = b - c; // b - c 已经是负数，赋值给a，a是无符号数，会变成一个很大的数。

    // good 规则调整为只对减法生效
    d = 0 | s;
    // good
    e += s;
    // good
    unsigned f = a * s;
}
