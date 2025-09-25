// defect:bkcheck(IntegerDiv)

int bad() {
    int num1 = 15;
    int num2 = 5;
    // bad
    num1 /= num2; // 告警
    // bad
    num2 = num1 / 3; // 告警
    // bad
    int num3 = num1 / num2; // 告警
    // bad
    return num3 / num2; // 告警
}