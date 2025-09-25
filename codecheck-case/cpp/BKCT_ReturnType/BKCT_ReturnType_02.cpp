#include <cstdint>
#include <string>

// define:bkcheck(ReturnType)
class Base1 {
    // 基类1的定义
public:
    Base1 getBase1();
    Base1 show1() {
        // good
        return getBase1();
    }
};

class Base2 {
    // 基类2的定义
public:
    Base2 getBase2();
    Base2 show2() {
        // good
        return getBase2();
    }
};

class Derived : public Base1, public Base2 {
    // 子类的定义，继承自Base1和Base2
public:
    Derived getDerived();
    Base1 show3(int a) {
        switch (a)
        {
        case 1:
            // good
            return getBase1();
        case 2:
            // bad
            return getBase2();
        default:
            // good 返回类型Derived为Base1的子类，是合法的
            return getDerived();
        }
    }
};