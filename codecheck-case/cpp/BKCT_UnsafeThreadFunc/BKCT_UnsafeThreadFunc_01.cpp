// define:bkcheck(UnsafeThreadFunc)

void bad() {
    time_t t = time(NULL);
    // bad
    struct tm *tm = localtime(&t);

    // bad
    printf("当前时间：%s", asctime(tm));
}

void bad2() {
    time_t t = time(NULL);
    // bad
    struct tm *tm = localtime(&t);

    // bad
    printf("当前时间2：%s", asctime(tm));
}