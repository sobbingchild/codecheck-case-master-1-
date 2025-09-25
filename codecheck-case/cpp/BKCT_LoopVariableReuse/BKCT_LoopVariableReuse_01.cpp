// defect:bkcheck(LoopVariableReuse)
#include <iostream>
#include <vector>

int n = 10, m = 10;

void bad_01() {
    // bad
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < m; i++) {
            // 内外循环都使用了相同的变量 'i'
            // 这可能导致逻辑错误或意外行为
        }
    }
}

void bad_02() {
    // bad
    for (int i = 0; i < n; i++) {
        int i = -1;
    }
    long arr[]{1, 3, 7};
    for (auto [i, j, k] = arr; i + j < k; ++i)
        std::cout << i + j << ' ';
}

void bad_03() {
    long arr[]{1, 3, 7};
    // bad
    for (auto [i, j, k] = arr; i + j < k; ++i) {
        for (int i = 0; i < m; i++) {
            // 内外循环都使用了相同的变量 'i'
        }
    }
}

void bad_04() {
    std::vector<int> v1 = {3, 1, 4, 1, 5, 9};
    std::vector<int> v2 = {3, 1, 4, 1, 5, 9};
    // bad
    for (auto iter = v1.begin(); iter != v1.end(); ++iter) {
        for (auto iter = v2.begin(); iter != v2.end(); ++iter) {

        }
    }
}