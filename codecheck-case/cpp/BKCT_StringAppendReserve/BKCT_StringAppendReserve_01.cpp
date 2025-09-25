#include <stdlib.h>
#include <iostream>

// define:bkcheck(StringAppendReserve)
void bad_01() {
    std::string element;
    element.push_back('a');
    //bad : string variable should reserve space before push back new character
    element.push_back('a');
}

void bad_02() {
    std::string element;
    element.append("a");
    //bad : string variable should reserve space before push back new character
    element.append("a");
}

void bad_03() {
    std::string element;
    element.insert(1, "a");
    //bad : string variable should reserve space before push back new character
    element.insert(1, "a");
}

void bad_04(int a) {
    std::string element;
    std::string str = "hello";
    if (a > 0) {
        element.reserve(5);
        element.insert(1, str);
    }
    element.insert(2, str);
    //bad : string variable should reserve space before push back new character
    element.insert(2, str);
}

void good() {
    std::string element;
    element.reserve(5);
    //good
    element.push_back('a');
}