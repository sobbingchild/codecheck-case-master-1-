#include <iostream>
#include <ostream>
#include <string>
//
// Created by wadema on 24-8-8.
//
// define:bkcheck(ForOuterIndex)
void bad()
{
    long arr[]{1, 3, 7};
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            // bad
            std::cout << arr[i] << std::endl;
            // good
            std::cout << arr[j] << std::endl;
        }
    }
}
