// defect:bkcheck(SocketTimeoutSetDetect)

void bad_01() {
    // bad
    SetSocketTimeoutUSec(iSocketTimeoutUSec); // 建议使用ResetSocketTimeout，而不是SetSocketTimeoutUSec
}

// bad
SetSocketTimeoutUSec(iSocketTimeoutUSec);

void bad_02() {
    // bad
    foo(SetSocketTimeoutUSec(iSocketTimeoutUSec));
}

void bad_03() {
    while (true) {
        // bad
        SetSocketTimeoutUSec(iSocketTimeoutUSec);
        break;
    }
}

void good() {
    // good
    ResetSocketTimeout(s, ms, us);
}