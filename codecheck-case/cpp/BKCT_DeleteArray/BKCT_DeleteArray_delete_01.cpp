
// defect:bkcheck(DeleteArray)

void bad_01() {
    int *pA = new int[10];
    // bad: delete the pointer,not the array pointer
    delete pA;
    pA = nullptr;
}

void good() {
    int *pA = new int[10];
    // good
    delete[] pA;
    pA = nullptr;
}

struct auto_ptr {
    auto_ptr() : ptr(0) {}

    ~auto_ptr() { delete ptr; }

    int *ptr;
};

void bad_02() {
    auto_ptr *arr = new auto_ptr[2];
    arr[0].ptr = new int(0);
    arr[1].ptr = new int(1);
    // bad
    delete arr;  // Memory leak, destructors are not called (or worse!)
}

void bad_03() {
    char *buf = new char[10];
    // bad
    delete buf; // Defect: should be delete[] buf
}

void bad_04() {
    char *buf = new char[10];
    while (true) {
        // bad
        delete buf; // Defect: should be delete[] buf
        break;
    }
}