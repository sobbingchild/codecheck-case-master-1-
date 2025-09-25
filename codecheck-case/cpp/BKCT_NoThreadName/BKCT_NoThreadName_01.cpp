//
// Created by wadema on 24-11-27.
//
// define:bkcheck(NoThreadName)

#include <iostream>
#include <thread>
#include <pthread.h>
#include <cstring>

void threadFunction()
{
}

int bad_01()
{
    // bad 没有设置线程名称
    std::thread myThread(threadFunction);
    myThread.join();
    return 0;
}

int good_01()
{
    // good
    std::thread myThread(threadFunction);
    // 设置线程的名字
    if (pthread_setname_np(myThread.native_handle(), "MyThread") != 0)
    {
        std::cerr << "Failed to set thread name" << std::endl;
        return 1;
    }
    myThread.join();
    return 0;
}

void* threadFunction(void* arg)
{
    return NULL;
}

int bad_02()
{
    pthread_t thread;
    // bad 没有设置线程名称
    if (pthread_create(&thread, NULL, threadFunction, NULL) != 0)
    {
        std::cerr << "Failed to create thread" << std::endl;
        return 1;
    }
    if (pthread_join(thread, NULL) != 0)
    {
        std::cerr << "Failed to join thread" << std::endl;
        return 1;
    }
    return 0;
}

int good_02()
{
    pthread_t thread;
    const char* name = "MyThread";
    // good
    if (pthread_create(&thread, NULL, threadFunction, NULL) != 0)
    {
        std::cerr << "Failed to create thread" << std::endl;
        return 1;
    }
    // 设置线程的名字
    if (pthread_setname_np(thread, name) != 0)
    {
        std::cerr << "Failed to set thread name" << std::endl;
        return 1;
    }
    if (pthread_join(thread, NULL) != 0)
    {
        std::cerr << "Failed to join thread" << std::endl;
        return 1;
    }
    return 0;
}

void bad_03()
{
    auto future = []()
    {
        foo();
    };
    // bad
    auto thread_ptr_ = std::make_unique<std::thread>(future);
}

void good_03()
{
    auto future = []()
    {
        foo();
    };
    // good
    auto thread_ptr_ = std::make_unique<std::thread>(future);
    pthread_setname_np(thread_ptr_->native_handle(), "MyThread");
}
