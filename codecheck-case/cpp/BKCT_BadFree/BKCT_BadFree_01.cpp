// defect:bkcheck(BadFree)

#include <cstdlib>

struct S {
    int a[4];
};

void bad_01(struct S *s) {
    int stackarray[3];
    int *p = stackarray;
    // bad
    free(p);  // 错误地试图释放栈上分配的内存，导致未定义行为。
    // bad
    free(s->a);  // 错误地尝试释放结构体的栈数组成员，导致未定义行为。
    // bad
    free((*s).a);  // 错误地尝试释放结构体的栈数组成员，导致未定义行为。
}

int (*fnptr)(int);

void bad_02() {
    // bad
    free(fnptr);  // 错误地尝试释放函数指针，导致未定义行为。
}

int bad_03() {
    int *ptr = nullptr;
    // bad
    free(ptr); // 试图释放一个未被分配的指针，导致未定义行为。
    return 0;
}

int good_01() {
    int *ptr = nullptr;
    // good
    delete ptr; // 不会引发错误
    return 0;
}

int bad_04() {
    int *ptr = new int;
    delete ptr;
    // bad
    delete ptr; // 二次释放同一个指针，导致未定义行为。
    return 0;
}

int bad_05() {
    int *ptr = (int *) malloc(sizeof(int));
    free(ptr);   // 此处正确释放内存
    // bad
    free(ptr);   // 此处尝试二次释放，导致未定义行为
    return 0;
}

int bad_06() {
    int value = 42;
    int *ptr = &value;
    // bad
    free(ptr); // 尝试释放栈内存，导致未定义行为。
    return 0;
}

int bad_07() {
    int value = 42;
    int *ptr = &value;
    // bad
    delete ptr;  // 错误地试图释放栈上分配的内存，导致未定义行为。
    return 0;
}

int bad_08() {
    int *ptr = new int;
    // bad
    free(ptr); // 错误地组合new操作符和free函数，导致未定义行为。
    return 0;
}

int bad_09() {
    int *ptr = (int *) malloc(sizeof(int));
    // bad
    delete ptr; // 错误地使用delete释放malloc分配的内存，导致未定义行为。
    return 0;
}
int bad_10(){
    int *ptr = nullptr;
    ptr = new int; // 赋值
    // bad
    free(ptr); // 错误地组合new操作符和free函数，导致未定义行为。
    return 0;
}