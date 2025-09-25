// defect:bkcheck(DevideByZero)

void good_01() {
    double divisor = 0.0;
    double dividend = 0.0;

    if (int(dividend) == 0) {
        return;
    }

    // good
    int quotient = (int)(divisor / dividend);
}