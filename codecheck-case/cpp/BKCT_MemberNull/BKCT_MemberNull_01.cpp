// define:bkcheck(MemberNull)
#include <iostream>

class MyClass {
public:
    int *ptr; // 指针成员变量
    TWeakObjectPtr <AActor> Target = nullptr;

    void doSomething() {
        // bad
        int value1 = *ptr;
        // bad
        if (Target->Imp()) {}
        if (ptr != nullptr) {
            // good
            int value = *ptr;
            std::cout << "value = " << value << std::endl;
        }
    }
};

class MyClass1 {
public:
    int *ptr; // 指针成员变量

    void doSomething() {
        int a = Math.random();
        if (a > 3) {
            return;
        }

//        if (a > 3) {
//            // 先忽略这个场景
//            int value1 = *(this->ptr);
//        }
        // bad
        int value2 = *(this->ptr);
        if (this->ptr != nullptr) {
            // good
            int value = *(this->ptr);
            std::cout << "value = " << value << std::endl;
        }
    }
};


class MyClass2 {
public:
    int *ptr;

    void setValue(int value) {
        // bad
        *ptr = value; // 在此处解引用，但未检查 ptr 是否为空
    }

    int getValue() {
        // bad
        return *ptr; // 在此处解引用，但未检查 ptr 是否为空
    }
};
