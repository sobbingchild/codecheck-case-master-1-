// defect:bkcheck(CreateNull)
#include "../../common/bkct_class.h"

using namespace bkct;

void bad() {
    CommonClass *p = CreateCommonClass();
    // bad
    p->SimpleFunc();
}

void bad1() {
    CommonClass *p = CreateCommonClass();
    if (p == nullptr) {
        // bad
        p->SimpleFunc();
    }
}

void bad2() {
    CommonClass *p = CreateCommonClass();
    if (p != nullptr) {
        return;
    }
    // bad
    p->SimpleFunc();
}

void bad3() {
    CommonClass *p = nullptr;
    // bad
    p->SimpleFunc();
}


void good() {
    CommonClass *p = CreateCommonClass();
    if (p != nullptr) {
        // good
        p->SimpleFunc();
    }
}

