// defect:bkcheck(ResourceLeak)
#include <stdlib.h>

int bad_01() {
    char *buffer = (char *) malloc(100);
    if (buffer == NULL) {
        return -1;
    }
    // ... 其他操作

    // bad 漏掉了 free(buffer);
    return 0;
}

int bad_02() {
    char *buffer = (char *) malloc(100);
    if (nullptr == buffer) {
        return -1;
    }
    // ... 其他操作

    // bad 漏掉了 free(buffer);
    return 0;
}

void bad_03() {
    char *buffer = (char *) malloc(100);
    if (buffer == NULL) {
        return;
    }
    // ... 其他操作

// bad 漏掉了 free(buffer);
}

int bad_04() {
    char *buffer = (char *) malloc(100);
    if (buffer != NULL) {
        // ... 其他操作
    } else {
        return 0;
    }

    // bad 漏掉了 free(buffer);
    return 0;
}

int bad_05() {
    char *buffer = (char *) malloc(100);
    if (buffer != NULL) {
        // ... 其他操作
        // bad 漏掉了 free(buffer);
        return 1;
    } else {
        return 0;
    }

    return 0;
}


int bad_06(int c) {
    void *p = malloc(10);
    if (c)
        // bad
        return -1;   // "p" is leaked
    /* ... */
    free(p);
    return 0;
}

int bad_07(int c) {
    void *p = malloc(10);
    if (p)
        // bad
        return -1;   // "p" is leaked

    return 0;
}

int bad_08(int c) {
    void *p = malloc(10);
    if (!p)
        return -1;
    /* ... */
    // bad "p" is leaked
    return 0;
}

int bad_09_10() {
    void *p = malloc(10);
    void *q = malloc(20);
    if (!p || !q)
        // bad(n:2)
        return -1; // "p" or "q" may be leaked if the other is NULL
    /*...*/
    free(q);
    free(p);
    return 0;
}

int bad_11() {
    void *p = malloc(10);
    void *q = malloc(20);
    if (!p && !q)
        // good
        return -1;
    /*...*/
    free(q);
    // bad "p" is leaked
    return 0;
}

int good_01() {
    void *p = malloc(10);
    void *q = malloc(20);
    if (!p && !q)
        // good
        return -1;
    /*...*/
    free(q);
    free(p);
    return 0;
}