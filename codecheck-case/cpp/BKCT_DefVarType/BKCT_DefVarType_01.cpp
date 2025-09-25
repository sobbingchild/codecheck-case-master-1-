//
// Created by wadema on 24-8-30.
//
// define:bkcheck(DefVarType)
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <regex>

void threadFunction()
{
    std::cout << "Hello from thread!" << std::endl;
}

void bad()
{
    // bad
    char16_t c1 = 1;
    // bad
    char32_t c2 = 1;
    // good
    char c3 = 1;

    // bad std::mutex：用于线程间的互斥锁。
    std::mutex mtx;

    // bad std::condition_variable：用于线程间的条件变量。
    std::condition_variable cv;

    // bad std::thread：用于创建和管理线程。
    std::thread t(threadFunction);
    t.join();

    // bad std::regex：用于正则表达式操作。
    std::regex pattern("world");

    // bad
    std::unique_ptr<int> ptr(new int(10)); // 独占管理堆上的整型对象
    // good
    std::shared_ptr<int> sp = std::make_shared<int>(10);
    // bad
    std::weak_ptr<int> wp = sp; // wp 不影响所指对象的引用计数
}
