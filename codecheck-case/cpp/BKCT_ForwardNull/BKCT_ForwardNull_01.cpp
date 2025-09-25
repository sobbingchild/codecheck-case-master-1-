// defect:bkcheck(ForwardNull)


int bad_01(int *p) {
    int x;
    if (p == NULL) { // 检查 p 是否为 NULL
        x = 0;
        // bad
        x = *p; // 在为空的分支中使用，给出告警
        // 告警压缩 bad
        x = *p; // 在为空的分支中使用，给出告警
    } else {
        x = *p;
    }
    x++;
    // 告警压缩 bad
    *p = x;   // 首先检查 p 是否为 NULL，然后在不再次检查是否为 NULL 的情况下解引用
    return 0;
}

void bad_02(int *p) {
    if (p) {
        return;
    } else {

    }
    // bad
    *p = 1;// p为空，需要报
}

void bad_03(int *p) {
    if (p == nullptr) {

    } else {
        return;
    }
    // bad
    *p = 1;// 为空，报
}

void bad_04(int *p) {
    if (p != nullptr) {
        return;
    } else {

    }
    // bad
    *p = 1;// 为空，报
}

void good_01(int *p) {
    if (!p) {
        return;
    }
    // good
    *p = 1;// p不为空，不能报
}

void good_02(int *p) {
    if (p != nullptr) {

    } else {
        return;
    }
    // good
    *p = 1;// 不为空，不用报
}