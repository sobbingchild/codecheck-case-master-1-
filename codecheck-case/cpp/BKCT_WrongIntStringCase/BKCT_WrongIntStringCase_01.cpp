// defect:bkcheck(WrongIntStringCase)
#include <string>
void bad_01(int **aa) {
    int a = 0, b = 1;
    // bad
    std::string s = a;
    // bad
    s = **aa;
    // bad
    s += b;
    s = s + "aa";
}

std::string bad_02() {
    int a;
    // bad
    return a;
}

