// define:bkcheck(NullPointDereference)
#include <stdlib.h>
void bad() {
    char* p = nullptr;
    //bad: pointer dereference after assigning null
    *p = 'a';
}

void bad1() {
    char* p = nullptr;
    if (p == NULL) {
        //bad: pointer dereference after judging value of null
        *p = 'a';
    }
}

void bad2() {
    char* q = NULL;
    char* p = q;
    //bad: pointer dereference after assigning with value of null
    *p = 'a';
}

void bad3() {
    char* p = nullptr;
    if (p != NULL) {
        return;
    }
    //bad: pointer dereference after judging value of null
    *p = 'a';
}