//
// Created by wadema on 24-6-18.
//
// defect:bkcheck(IfNoAssign)

void bad_01() {
    int a;
    // bad
    if (a = 1) {

    }
}

void bad_02() {
    int a, b = 1;
    // bad
    if (a = 1 && b == 0) {

    }
}

void bad_03() {
    int a, b = 1;
    // bad
    if (a = 0 || b == 0) {

    }
}

void bad_04() {
    int a, b = 1;
    // bad
    if ((a = 0) || b == 0) {

    }
}

void good() {
    int a = 1;
    // good
    if (a == 1) {

    }
}

void good_02() {
    int a;
    // good
    if ((a = 1) == 1) {

    }
}