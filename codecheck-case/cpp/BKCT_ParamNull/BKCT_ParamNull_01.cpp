// define:bkcheck(ParamNull)
#include <stdlib.h>
#include "../../common/bkct_class.h"

using namespace bkct;

void bad(CommonClass *p) {
    //bad: a is dereferenced with value of possibly null
    p->SimpleFunc();
}

void bad1(CommonClass *p) {
    if (p == nullptr) {
        // bad
        p->SimpleFunc();
    }
}

void bad2(CommonClass *p) {
    if (p != nullptr) {
        return;
    }
    // bad
    p->SimpleFunc();
}

void bad3(CommonClass *p) {
    if (p != nullptr) {
        int a = 1;
    } else {
        // bad
        p->SimpleFunc();
    }
}

void good(int *a) {
    if(a != nullptr) {
        //good
        *a = 2;
    }
}