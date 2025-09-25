
// defect:bkcheck(DupNameVariable)

int bad_01() {
    int a = 1;
    {
        // bad
        int a = 0;
    }
    if (a) {
        return a;
    }
    return 0;
}

int bad_02() {
    int x = 10;
    if (true) {
        // bad
        int x = 20; // 定义重名变量x，会隐藏外部的变量x
        std::cout << x << std::endl; // 输出20
    }
    std::cout << x << std::endl; // 输出10
}

int bad_03() {
    int x = 10;
    while (true) {
        // bad
        int x = 20; // 定义重名变量x，会隐藏外部的变量x
        std::cout << x << std::endl; // 输出20
        break;
    }
    std::cout << x << std::endl; // 输出10
}

void bad_04() {
    int x = 10;
    for(int i = 0; i < 10; i++) {
        // bad
        int x = 20; // 定义重名变量x，会隐藏外部的变量x
        std::cout << x << std::endl; // 输出20
    }
    std::cout << x << std::endl; // 输出10
}