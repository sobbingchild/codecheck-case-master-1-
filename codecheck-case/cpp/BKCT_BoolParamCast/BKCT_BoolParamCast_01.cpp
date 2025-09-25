// defect:bkcheck(BoolParamCast)

void foo(long long id) {

}

void foo(int id, bool b) {

}

void bar() {
    bool a = true;
    // bad
    foo(a);
    // bad
    foo(false);
    // bad
    foo(a, false);
    // bad
    foo(false, true);
}