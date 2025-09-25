// defect:bkcheck(OverflowBeforeWiden)

long long int bad(unsigned long long zz) {
    unsigned int x = 2147483648;
    unsigned int y = 22;
    int x1 = 2147483647;
    unsigned long long z;
    // bad
    if ((x * y) == z) {
        // Do something.
    }
    // bad
    if ((x1 * y) == z) {
        // Do something.
    }
    long long z1;
    for (int i = 0; i < 2147483647; ++i) {
        for (int j = 0; j < 2147483647; ++j) {
            // bad
            if ((i * j) == z1) {            // 可能溢出，应该报
                // Do something.
            }
        }
    }
    unsigned int y1 = 22;
    // bad
    return 214748364 * y1;
}
