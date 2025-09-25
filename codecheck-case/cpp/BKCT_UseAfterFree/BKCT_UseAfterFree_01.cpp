// defect:bkcheck(UseAfterFree)

int ext(int *p) {
    return 0;
}

void bad(int *p) {

    free(p);
    // bad
    int k = *p;            // 在指针被释放后解引用了该指针

    int *a = static_cast<int *>(malloc(8));
    free(a);
    // bad
    int res = a[3];       // 被解引用的已释放指针

    int *b = static_cast<int *>(malloc(8));
    free(b);
    // bad
    ext(b);            // 已释放指针作为参数使用

    int *c = static_cast<int *>(malloc(8));
    free(c);
    // bad
    free(c);      // 双重free

    int *d = static_cast<int *>(malloc(8));
    free(d);
    // bad
    d[2] = 1;             // 被解引用的已释放指针
}