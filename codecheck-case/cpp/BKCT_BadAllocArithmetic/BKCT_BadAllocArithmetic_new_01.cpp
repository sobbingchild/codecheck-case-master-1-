// define:bkcheck(BadAllocArithmetic)

void bad(int a, int b) {
    // bad: addition operation
    char *p = new char[a] + b;
    
    // bad: substraction operation
    char *q = new char[a] - b;
}