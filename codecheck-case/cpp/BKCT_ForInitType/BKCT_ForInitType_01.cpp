// defect:bkcheck(ForInitType)

void bad() {
    // bad:for循环游标类型必须为int32_t或int，告警！
    for (long int i = 0; i < 5; ++i) {

    }
    // bad:死循环
    for (uint32_t i = 0; i >= 0; --i) {

    }
}

typedef long int int64;

void bad_() {
    // bad:for循环游标类型必须为int32_t或int，告警！
    for (int64 i = 0; i < 5; ++i) {

    }
    // bad
    for (uint64_t i = 0; i >= 0; --i) {

    }
}

void good() {
    // good
    for (int32_t i = 0; i < 5; ++i) {

    }
    // good
    for (int i = 0; i < 5; ++i) {

    }
}