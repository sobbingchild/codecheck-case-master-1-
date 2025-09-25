// defect:bkcheck(InfiniteLoop)


void good_01() {
    int i = 0;
    int j = 0;
    // good
    while (i < 10) {
        ++i;
    }
}

void good_02() {
    int i = 0;
    int j = 0;
    // good
    while (true) {
        j++;
        if (j > 0) {
            break;
        }
    }
}

void good_03() {
    int i = 0;
    int j = 0;
    // good
    do {
        ++i;
    } while (i < 10);
}

void good_04() {
    int i = 0;
    int j = 0;
    // good
    do {
        j++;
        if (j > 0) {
            return;
        }
    } while (true);
}

void good_05() {
    int j = 0;
    // good
    for (int i = 0; i < 10; ++j) {
        i++;
    }
}

void good_06() {
    int j = 0;
    // good
    for (int i = 0; i < 10; ++i) {
        j++;
    }
}

void good_07() {
    int j = 0;
    // good
    for (int i = 0;; ++j) {
        if (j > 0) {
            exit(1);
        }
    }
}

void good_08() {
    int j = 0;
    // good
    for (;;) {
        j++;
        if (j > 0) {
            abort();
        }
    }
}