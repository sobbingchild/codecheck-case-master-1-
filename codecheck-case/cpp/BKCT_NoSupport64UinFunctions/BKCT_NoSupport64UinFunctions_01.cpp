//defect:bkcheck(NoSupport64UinFunctions)

// bad
void bad_01(unsigned long lUin1) {
    // do something
}

// bad
void bad_02(unsigned int lUin2) {
    // do something
}

// bad
void bad_03(short lUin3) {
    // do something
}

// bad
void bad_04(uint32_t lUin4) {
    // do something
}

// good
void good_01(unsigned long long lUin5,unsigned long long int iUin5) {
    // do something
}

// good
void good_02(uint64_t lUin6) {
    // do something
}

typedef unsigned long long uint;

// good
void good_03(uint lUin7) {
    // do something
}

typedef uint64_t uint64;

// good
void good_04(uint64 lUin8) {
    // do something
}