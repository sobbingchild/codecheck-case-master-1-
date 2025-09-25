//
// Created by wadema on 2024/5/16.
//
// define:bkcheck(DirectNullPointer)
#include <iostream>
#include <vector>
#include <algorithm>

// lambda表达式的场景
void bad_good() {

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用lambda表达式来计算所有元素的和
    int sum = 0;
    std::for_each(numbers.begin(), numbers.end(), [&sum](int n) {
        // bad
        Single->Call->Onclicked.Add();
        if (Single && Single->Call) {
            // good
            Single->Call->Onclicked.Add();
        }
        sum += n;
    });

    std::cout << "Sum: " << sum << std::endl;

}

