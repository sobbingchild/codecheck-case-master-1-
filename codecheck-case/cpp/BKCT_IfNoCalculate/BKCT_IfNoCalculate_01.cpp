//
// Created by wadema on 24-6-18.
//
// defect:bkcheck(IfNoCalculate)

void bad_01(int a, int b, int c) {
    // bad
    if (a + b < c) {

    }
}

void bad_02(int a, int b, int c) {
    // bad
    if (a < b + c) {

    }
}

void bad_03(int a, int b, int c) {
    // bad
    if ((a + b) < c) {

    }
}

void bad_04(int a, int b, int c) {
    // bad
    if (a == 1 && a + b < c) {

    }
}

void good(int a, int b, int c) {
    int d = a + b;
    // good
    if (d < c) {

    }
}
