#include <stdlib.h>

// define:bkcheck(OverRun)
void bad_01() {
    int n[10];
    int a = rand() % 15;
    //bad: integer a possibly greater than 10
    n[a] = 3;
}

void bad_02() {
    int *n = new int[10];
    int a = rand() % 15;
    //bad: integer a possibly greater than 10
    n[a] = 3;
}
void bad_03() {
    int *buffer = (int *) malloc(10 * sizeof(int)); // 40 bytes
    int i = 0;
    for (; i <= 10; i++) {   // Defect: writes buffer[10] and overruns memory
        // bad
        buffer[i] = i;
    }
}

void bad_04() {
    int *buffer = (int *) malloc(10 * sizeof(int)); // 40 bytes
    int i = 0;
    while (i <= 10) {   // Defect: writes buffer[10] and overruns memory
        // bad
        buffer[i] = i;
        i++;
    }
}

void good() {
    int n[10];
    int a = rand() % 10;
    //good
    n[a] = 3;
}