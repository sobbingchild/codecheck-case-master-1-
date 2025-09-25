// defect:bkcheck(NoArithmeticOnFloatPoint)

void bad() {
    // bad
    float a = 3.14 * 0.618;  // 应检测
    float b = 1.0;
    // bad
    float c = a + b;  // 应检测
    // bad
    float d = c + 1.0;  // 应检测
    // bad
    float e = c + d;  // 应检测
}