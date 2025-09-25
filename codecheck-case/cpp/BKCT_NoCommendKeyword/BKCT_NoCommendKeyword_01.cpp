//
// Created by wadema on 24-8-30.
//
// define:bkcheck(NoCommendKeyword)

#include <iostream>
// 关键字1 alignas：指定类型或对象的对齐方式。---------------------------------------------
// bad
alignas(16) int x; // x 的对齐方式为 16 字节
// bad
struct alignas(16) MyStruct
{
    int a;
    double b;
};

struct MyAlignedType
{
    // bad
    alignas(32) char data[64];
};

// 关键字2 alignof：获取类型的对齐要求。----------------------------------------------------
void bad_02()
{
    // bad
    std::cout << alignof(double) << std::endl; // 输出 double 类型的对齐要求
    // bad
    std::cout << alignof(MyStruct) << std::endl;
}

// 关键字3 constexpr：指定常量表达式，允许在编译时进行计算。------------------------------------
// bad
constexpr int square(int x) { return x * x; }

int bad_03()
{
    // bad
    constexpr int result = square(10); // 编译时计算
    return 0;
}

struct Point
{
    int x, y;
    // bad
    constexpr Point(int x, int y) : x(x), y(y)
    {
    }
};

// bad
constexpr Point p(1, 2); // 编译时计算


// 关键字4 decltype：推断表达式的类型。---------------------------------------------------
int a = 5;
// bad
decltype(a) b = 10; // b 的类型与 a 相同，为 int
// bad
decltype(a + b) c = a + b;
auto func1 = []() -> int { return 42; };
// bad
decltype(func1()) result = func1(); // result 的类型是 int
template <typename T, typename U>
// bad
auto add(T t, U u) -> decltype(t + u)
{
    return t + u;
}

// 关键字5 noexcept：指定函数不会抛出异常。------------------------------------------------
// bad
void func() noexcept
{
    /* 不会抛出异常的函数体 */
}

// bad
template <typename T>
void swap(T& a, T& b) noexcept(noexcept(T(std::declval<T>())))
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}



// 关键字7 thread_local：指定变量为线程局部存储。---------------------------------------------
// bad
thread_local int xx = 0; // 每个线程都有自己独立的 x 变量


// 关键字8 override：显式指定重写基类的虚函数。--------------------------------------------------
struct Base
{
    virtual void func();
};

struct Derived : Base
{
    // bad
    void func() override; // 确保 func 重写了基类的虚函数
};

class Animal
{
public:
    virtual void speak() const
    {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal
{
public:
    // bad
    void speak() const override
    {
        // 使用 override 关键字
        std::cout << "Dog barks" << std::endl;
    }
};

// 关键字9 final：防止类被继承或防止虚函数被重写。-------------------------------------------------
// bad
class Basef final
{
    /* Basef 类不能被继承 */
};

struct A
{
    // bad
    virtual void func() final; // func 不能被重写
};
