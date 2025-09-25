
// defect:bkcheck(ConstValidate)

// bad: i is a const variable
void bad_01(const int i) {
    // i is a const variable
    i = 10;
}

// bad: a is a const variable
void bad_02(const char a) {
    // a is a const variable
    a = 'c';
}

// bad: s is a const variable
void bad_03(const char *s) {
    s = "hello";
}

// bad: a is a const variable
void bad_04(const int a, const int b) {
    // a is a const variable
    a = b;
}

void good(const int i) {
    // good
    *(const_cast<int *>(&i)) = 10;
}
