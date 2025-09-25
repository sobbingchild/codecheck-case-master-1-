// defect:bkcheck(BadSizeof)

#include <iostream>

struct Foo {
public:
    virtual ~Foo() {}

    int MyMethod(char x) { return x + 1; }

    virtual char MyVirtualMethod(int /* n */) { return 'a'; }

    int value;
};


int main() {

    std::cout << &Foo::value << std::endl;
    // good &Foo::value 这种语法被称为 "取成员指针"，它返回一个成员指针，指向 Foo 类内部 value 成员变量的相对地址（也可以视为在对象中的偏移量）。
    std::cout << sizeof(&Foo::value) << std::endl;
}
