// defect:bkcheck(NegativeReturns)
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <array>

#include<stack>
#include <bitset>
#include <iostream>

using namespace std;

void bad_17(int y, int z, int x1, std::vector<int> vp, std::string sp) {
    int x = -1;
    int buff[1024];
    // bad
    buff[x] = 0;            // “x”为负数被用作数组索引
    // bad
    void *ptr16 = malloc(x); // “x”为负数被传递给不可能为负的参数

    if (y < 0) {            // 进入if或者while等分支中
        // bad
        buff[y] = 0;            // “x”可能为负被用作数组索引
        // bad
        void *ptr17 = malloc(y); // “x”可能为负被传递给不可能为负的参数
    }

    do {
        buff[z] = 0;
        void *ptr1 = malloc(z);
    } while (z > 0);
    // bad
    buff[z] = 0;            // “x”可能为负被用作数组索引
    // bad
    void *ptr18 = malloc(z); // “x”可能为负被传递给不可能为负的参数

    for (int i = 0; x1 < 0 && i < 10; i++) {            // 进入if或者for等分支中
        // bad
        buff[x1] = 0;            // “x”可能为负被用作数组索引
        // bad
        void *ptr1 = malloc(x1); // “x”可能为负被传递给不可能为负的参数
    }
    // bad
    vp[-1] = 1;             // bk
    // bad
    sp[-3] = '1';            // bk
    std::vector<int> vi; //定义一个vi数组
    std::vector<int>::iterator it = vi.begin();//声明一个迭代器指向vi的初始位置
    std::vector<int> vArrary = {7, 5, 16, 8};
    printf("v[0]: %d\n", vArrary[0]);
    printf("v[1]: %d\n", vArrary[1]);
    // bad
    printf("v[-1]: %d\n", vArrary[-1]);            // bk
    // bad
    printf("v[-2]: %d\n", vArrary[-2]);            // bk
    // bad
    vArrary[-3] = 0;            // bk
    std::vector<int> vArrary2;
    // bad
    vArrary[-1] = 0;            // bk
    std::string s = "123";
    // bad
    s[-1] = '1';            // bk
    std::stack<int> sta;

    bitset<4> foo("1011");
    // bad
    cout << foo[-1] << endl;            // bk
    std::array<int, 4> arr = {};
    // bad
    arr[-1] = 1;            // bk
}
