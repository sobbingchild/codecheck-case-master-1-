// defect:bkcheck(LoopLimit)


void bad_01() {
    // bad
    for (;;) { // 无限循环给出告警
        // 循环体语句
    }
}

void bad_02() {
    // bad
    while (true) { // 无限循环给出告警
        // 循环体语句
    }

}

void bad_03() {
    do {
        // 循环体语句
        // bad
    } while (true); // 无限循环给出告警
}

void bad_04() {
    // bad
    for (int i = 1;; i++) { // 无限循环给出告警
        // 循环体语句
    }
}