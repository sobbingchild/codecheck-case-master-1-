// defect:bkcheck(UnusedValue)

int bad_01() {
    int a, b;
    a = 0;
    // bad
    b = 1;  // UnusedValue
    return a;
}

int bad_02() {
    int x = 10, y = 20;
    while (x > 5) {
        // bad
        y = x;
        x--;
    }
    printf("x = %d\n", x);
    return 0;
}

int bad_03() {
    int x = 10, y = 20;
    if (x > 5) {
        // bad
        y = x;
        return x;
    }
    printf("x = %d\n", x);
    return 0;
}

int bad_04() {
    int x = 10, y;
    // bad
    y = x + 1;
    return 0;
}

int good() {
    int a = 0;
    int &b = a;
    a = 1;
    if (a > 0) {
        b = 2;
        return 0;// 变量的引用先屏蔽了，这里理论上需要告警
    }
    return a + b;
}