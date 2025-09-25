// defect:bkcheck(JSONUseDetect)

void bad_01() {
    // bad
    Json::Value root; // 尽量使用JSON183不使用JSON。
}

void bad_02() {
    // bad
    Json::Value root = get(); // 尽量使用JSON183不使用JSON。
}

// bad
typedef Json::Value jva;

void bad_03() {
    // bad
    Json::Reader reader; // 尽量使用JSON183不使用JSON。
}

void good() {
    // good
    Json183::Value root;
}