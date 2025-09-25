// defect:bkcheck(VariableInit)

void bad() {
    int x = 5; // 定义整型变量 x，并把它初始化为 5
    double y{3.14}; // 使用花括号来初始化变量 y 为浮点型 3.14
    int a(10); // 等价于 int a = 10;
    float b = float(10.0); // 通过类转换来实现拷贝初始化
    // bad
    int e; // 未初始化，给出告警
    // bad
    int c, d; // 未初始化，给出告警
    // bad
    int f = 0, g; // 未初始化，给出告警
    // bad
    int h, i = 1; // 未初始化，给出告警
}