// defect:bkcheck(OverRunCustom)

void bad_01(int index) {
    int a[5] = {0};
    // bad
    a[index] = 2;// 入参index作为数组索引使用时存在越界可能，建议对索引大小进行判断
}

void bad_02(int index) {
    int *a = new int[5];
    // bad
    a[index] = 2;// 入参index作为数组索引使用时存在越界可能，建议对索引大小进行判断
}

void bad_03(int i) {
    int *buffer = (int *) malloc(10 * sizeof(int)); // 40 bytes
    for (; i <= 10; i++) {   // Defect: writes buffer[10] and overruns memory
        // bad
        buffer[i] = i;
    }
}

void bad_04(int i) {
    int *buffer = (int *) malloc(10 * sizeof(int)); // 40 bytes
    while (i <= 10) {   // Defect: writes buffer[10] and overruns memory
        // bad
        buffer[i] = i;
        i++;
    }
}

void good(unsigned int index) {
    int a[5] = {0};
    if (index >= 5) {
        return;
    }
    // good
    a[index] = 2;
}