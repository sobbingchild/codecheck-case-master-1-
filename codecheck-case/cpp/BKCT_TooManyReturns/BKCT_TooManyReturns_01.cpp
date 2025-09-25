// defect:bkcheck(TooManyReturns)

// bad
bool bad(int x, int y) {
    if (x < 0 || y < 0) {
        return false;
    }
    if (x % 2 == 0 && y % 2 == 0) {
        return true;
    }
    if (x % 2 == 1 && y % 2 == 1) {
        return true;
    }
    if (x == 0 && y == 0) {
        return true;
    }
    return false;
} // 函数中有5处return，建议使用do ... while(false)的⽅式进⾏替换

// bad
bool bad_02(int x, int y) {
    if (x < 0 || y < 0) {
        return false;
    }
    if (x % 2 == 0 && y % 2 == 0) {
        return true;
    }
    if (x % 2 == 1 && y % 2 == 1) {
        return true;
    }
    if (x == 0 && y == 0) {
        return true;
    }
    if (x == y) {
        return true;
    }
    return false;
} // 函数中有6处return，建议使用do ... while(false)的⽅式进⾏替换
// bad
bool bad_03(int x, int y) {
    if (x < 0 || y < 0) {
        return false;
    }
    if (x % 2 == 0 && y % 2 == 0) {
        return true;
    }
    if (x % 2 == 1 && y % 2 == 1) {
        return true;
    }
    if (x == 0 && y == 0) {
        return true;
    }
    if (x == y) {
        return true;
    }
    if (x != y) {
        return true;
    }
    return false;
} // 函数中有7处return，建议使用do ... while(false)的⽅式进⾏替换
// bad
bool bad_04(int x, int y) {
    if (x < 0 || y < 0) {
        return false;
    }
    if (x % 2 == 0 && y % 2 == 0) {
        return true;
    }
    if (x % 2 == 1 && y % 2 == 1) {
        return true;
    }
    if (x == 0 && y == 0) {
        return true;
    }
    if (x == y) {
        return true;
    }
    if (x != y) {
        return true;
    }
    if (x > y) {
        return true;
    }
    return false;
} // 函数中有8处return，建议使用do ... while(false)的⽅式进⾏替换