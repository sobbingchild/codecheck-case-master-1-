// define:bkcheck(EmptyLoop)

void bad_01() {
    // bad: empty loop
    for (int i = 0; i < 10; i++) {

    }

    // bad: empty loop
    while (true) {

    }

}

void bad_02() {
    // bad: empty loop
    do {

    } while (true);
}

void bad_03() {
    // bad: empty loop
    for (;;) {

    }
}