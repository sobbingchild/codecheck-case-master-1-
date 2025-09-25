// defect:bkcheck(InfiniteLoop)

// 1、循环条件永真情况下，没有break或者return或者退出函数如exit()的场景
void bad_01() {
    int i = 0;
    int j = 0;
    // bad
    while (i < 10) {
        ++j;
    }
}

void bad_02() {
    int i = 0;
    int j = 0;
    // bad
    while (true) {
        ++j;
    }
}

void bad_03() {
    int i = 0;
    int j = 0;
    // bad
    do {
        ++j;
    } while (i < 10);
}

void bad_04() {
    int i = 0;
    int j = 0;
    // bad
    do {
        ++j;
    } while (true);
}

void bad_05() {
    int j = 0;
    // bad
    for (int i = 0; i < 10; ++j) {
        j++;
    }
}

void bad_06() {
    int j = 0;
    // bad
    for (int i = 0; true; ++j) {
        i++;
    }
}

void bad_07() {
    int j = 0;
    // bad
    for (int i = 0;; ++j) {
        i++;
    }
}

void bad_08() {
    int j = 0;
    // bad
    for (;;) {
        j++;
    }
}