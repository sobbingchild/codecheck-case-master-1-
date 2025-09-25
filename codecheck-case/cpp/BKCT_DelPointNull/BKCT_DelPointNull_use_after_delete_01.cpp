#include "../../common/bkct_class.h"
// defect:bkcheck(DelPointNull)

void bad_01() {
    bkct::CommonClass *p = new bkct::CommonClass();
    delete p;
    // bad: use after delete the object pointer
    p->SimpleFunc();
}

void bad_02() {
    int *p = new int(10);
    delete p;
    // bad
    int x = *p; // 解引用悬空指针p，可能会导致程序崩溃或产生未定义的行为
}

void bad_03() {
    int *p = new int[10];
    delete[] p;
    // bad
    int x = p[0]; // 解引用悬空指针p，可能会导致程序崩溃或产生未定义的行为
}


void bad_04() {
    bkct::CommonClass *p = new bkct::CommonClass();
    delete p;
    // bad
    bkct::CommonClass a = *p;
}

void good() {
    bkct::CommonClass *p = new bkct::CommonClass();
    delete p;
    p = nullptr;
    if (p != nullptr) {
        // good
        p->SimpleFunc();
    }
}