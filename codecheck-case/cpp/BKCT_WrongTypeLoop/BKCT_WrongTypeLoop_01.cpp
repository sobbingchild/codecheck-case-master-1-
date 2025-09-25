// defect:bkcheck(WrongTypeLoop)
int f() {
    std::string a = "aa";
    return 1;
}

void bad() {
    typedef short int uint16;
    typedef long long int uint64;
    long long int a = 256;
    long long int b = 256;
    uint16 c = 256;
    uint64 d = 256;
    // bad
    while (!(a < f())) {

    }
    do {
        // bad
    } while (c > d);
    // bad
    for (int i = 0; i < a; i++) {

    }
    // bad
    for (int i = 0; i < d; i++) {

    }
    // good
    for (long long int i = 0; i < a; i++) {

    }
}