//defect:bkcheck(NoSupport64UinVariables)
typedef unsigned long long uint;

typedef uint64_t uint64;

typedef struct {
    // bad
    uint32_t aUin1;
    // bad
    uint16_t bUin2;
    // good
    uint64_t cUin3;
    // good
    uint64 dUin3;

} PushData;
struct Test_Struct {
    // bad
    uint32_t aUin4;
    // bad
    uint16_t bUin5;
    // good
    uint64_t cUin6;
    // good
    uint dUin6;
};
// bad
uint32_t gUin7 = 1;
// good
uint64_t gUin8 = 1;

void bad_01() {
    // bad
    uint32_t lUin9 = 1;
}

void good_01() {
    // good
    uint64_t lUin10 = 1;
}

void good_02() {
    // good
    unsigned long long lUin11 = 1;
    // good
    unsigned long long int nUin11 = 1;
}


void good_03() {
    // good
    uint lUin12 = 1;
    // good
    uint64 lUin13 = 1;
}