//
// Created by wadema on 2024/5/16.
//
// define:bkcheck(DirectNullPointer)

void bad_01_02() {
    // bad
    A->foo()->bar() == a; // A->foo() 直接解引用
    // bad
    b = F->ptr->get(); // F->ptr 直接解引用
}

void bad_03_04() {
    // bad
    A->foo()->c == a; // A->foo() 直接解引用
    // bad
    b = F->ptr->d; // F->ptr 直接解引用
}

void good_01() {
    if (A->foo() == nullptr) {

    }
    // good
    A->foo()->bar() == a; // A->foo() 在上文中有判断
    // bad
    b = F->ptr->get(); // F->ptr 在下文中有判断，需要告警
    if (F->ptr != nullptr) {

    }
}

void good_02() {
    if (A->foo() == nullptr) {

    }
    // good
    A->foo()->c == a; // A->foo() 在上文中有判断
    // bad
    b = F->ptr->d; // F->ptr 在下文中有判断，需要告警
    if (F->ptr != nullptr) {

    }
}