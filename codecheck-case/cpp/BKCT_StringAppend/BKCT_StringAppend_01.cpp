#include <stdlib.h>
#include <iostream>

// define:bkcheck(StringAppend)
void bad_01() {
    std::string element = "abcd";
    //bad(n:2) : string should not be connected by
    std::string total = "123" + element;
}

void bad_02() {
    const char *element = "abcd";
    //bad : string should not be connected by
    std::string total = "123" + element;
}

void bad_03() {
    //bad(n:2) : string should not be connected by
    std::string total = "123" + "element";
}

void good() {
    std::string element = "abcd";
    std::string total = "123";
    //good
    total.append(element);
}