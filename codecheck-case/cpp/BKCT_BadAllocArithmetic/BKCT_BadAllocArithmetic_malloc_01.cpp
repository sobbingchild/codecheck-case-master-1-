#include <stdlib.h>
// define:bkcheck(BadAllocArithmetic)

void bad(int a, int b) {
    // bad: addition operation
    char *p = (char*)malloc(a) + b;
    
    // bad: substraction operation
    char *q = (char*)malloc(a) - b;
}