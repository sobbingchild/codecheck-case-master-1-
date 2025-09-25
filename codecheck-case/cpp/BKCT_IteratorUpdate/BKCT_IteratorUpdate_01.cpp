//
// Created by wadema on 24-11-26.
//
// defect:bkcheck(IteratorUpdate)
#include <iostream>
#include <vector>

void bad()
{
    map<string, TABLE_oRDER>::iterator it = m_mSubOrder.begin();
    // bad 循环中没有更新迭代器对象
    while (it != m_mSuborder.end())
    {
        TABLE_ORDER& stOrder = it->second;
    }
}

void good_01()
{
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    auto it = myVector.begin();
    // good 使用while循环进行迭代
    while (it != myVector.end())
    {
        std::cout << *it << " ";
        ++it;
    }
}

void good_02()
{
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = myVector.begin();
    // good 使用while循环进行迭代
    while (it != myVector.end())
    {
        std::cout << *it << " ";
        it++;
    }
}

void good_03()
{
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = myVector.begin();
    // good 使用while循环进行迭代
    while (it != myVector.end())
    {
        std::cout << *it << " ";
        it = it + 1;
    }
}
