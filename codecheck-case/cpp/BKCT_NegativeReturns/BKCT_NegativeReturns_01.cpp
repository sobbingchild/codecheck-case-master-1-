// defect:bkcheck(NegativeReturns)

void bad_01(int y) {
    int x = -1;
    int buff[1024];
    // bad
    buff[x] = 0;            // “x”为负数被用作数组索引
    // bad
    void *ptr16 = malloc(x); // “x”为负数被传递给不可能为负的参数

    if (y < 0) {            // 进入if或者while等分支中
        // bad
        buff[y] = 0;            // “x”可能为负被用作数组索引
        // bad
        void *ptr17 = malloc(y); // “x”可能为负被传递给不可能为负的参数
    }

    std::vector<int> vArrary = {7, 5, 16, 8};
    // bad
    printf("v[-1]: %d\n", vArrary[-1]);
}

void bad_02(int a[], string s, std::vector<int> v) {
    int x = -1, y = 0;
    // bad
    a[x] = 0;            // “x”为负数被用作数组索引
    // good
    a[y] = 0;
}

void bad_03(int (&arr)[5]) {
    int x = -1, y = 1;
    // bad
    arr[x] = 0;            // “x”为负数被用作数组索引
    // good
    arr[y] = 0;
}

void bad_04() {
    int *pA = new int[10];
    int x = -1;
    // bad
    pA[x] = 0;            // “x”为负数被用作数组索引
}

void bad_05() {
    int *pA;
    pA = new int[10];
    int x = -1;
    // bad
    pA[x] = 0;            // “x”为负数被用作数组索引
}