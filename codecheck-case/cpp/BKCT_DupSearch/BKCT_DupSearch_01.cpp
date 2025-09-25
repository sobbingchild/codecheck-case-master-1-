#include <stdlib.h>
#include <iostream>
#include <map>

// define:bkcheck(DupSearch)
void bad_01() {
    std::map<int, std::string> map;
    int key = 2;
    std::string value = map[key];
    //bad : search in map with same index
    std::string value1 = map[key];
}

void bad_02() {
    std::map<int, std::string> test_map;
    int key = 5;
    std::string value1 = test_map[key];
    // bad
    std::string value2 = test_map[key];
}

void bad_03() {
    std::map<int, std::string> test_map;
    int key = 5;
    std::string value1 = test_map[key];
    while (key > 0) {
        // bad
        std::string value2 = test_map[key];
        break;
    }
}

void bad_04() {
    std::map<int, std::string> test_map;
    int key = 5;
    std::string value1 = test_map[key];
    if (key > 0) {
        // bad
        std::string value2 = test_map[key];
    }
}