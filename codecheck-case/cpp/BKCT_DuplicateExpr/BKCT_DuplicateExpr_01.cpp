// defect:bkcheck(DuplicateExpr)


void bad_01() {
    int a, b;
    // bad:关系型表达式两端一致
    if (a == a) {
    }
}

void bad_02() {
    int a, b;
    // bad:关系型表达式两端一致
    if (a && a) {
    }
}

void bad_03() {
    int a, b;
    // bad:关系型表达式两端一致
    if (a >= a) {
    }
}

void bad_04() {
    int a, b;
    // bad:关系型表达式两端一致
    if (a < a) {
    }
}

void good() {
    int a, b;
    // good
    if (a != b) {
    }
}