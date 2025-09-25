//
// Created by wadema on 24-8-30.
//
// define:bkcheck(NoCommendMethod)
#include <iostream>
#include <regex>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    // bad std::all_of：检查范围内的所有元素是否满足条件。
    bool allPositive = std::all_of(vec.begin(), vec.end(), [](int i) { return i > 0; });
    std::cout << "All elements are positive: " << allPositive << std::endl;

    // bad std::any_of：检查范围内是否有任何元素满足条件。
    bool anyNegative = std::any_of(vec.begin(), vec.end(), [](int i) { return i < 0; });
    std::cout << "Any element is negative: " << anyNegative << std::endl;

    // bad std::none_of：检查范围内是否没有元素满足条件。
    bool noneNegative = std::none_of(vec.begin(), vec.end(), [](int i) { return i < 0; });
    std::cout << "No element is negative: " << noneNegative << std::endl;

    std::vector<int> src = {1, 2, 3, 4, 5};
    std::vector<int> dest(3);
    // bad std::copy_n：从一个范围复制指定数量的元素到另一个范围。
    std::copy_n(src.begin(), 3, dest.begin());
    return 0;
}

// 关键字 static_assert：在编译时进行断言检查。--------------------------------------------
// bad
static_assert(sizeof(int) == 4, "int size is not 4 bytes");

template <typename T>
void checkType()
{
    // bad
    static_assert(sizeof(T) == 4, "Type T must be 4 bytes");
}

