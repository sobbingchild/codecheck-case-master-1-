
// defect:bkcheck(DeleteVoid)

void bad_01(void *p) {
    // bad
    delete p;
}

void bad_02() {
    void *p;
    // bad
    delete p;
}

void bad_03() {
    void *p = nullptr;
    // bad
    delete p;
}

void bad_04(void *p) {
    if (p) {
        // bad
        delete p;
    }
    // bad
    delete p;
}