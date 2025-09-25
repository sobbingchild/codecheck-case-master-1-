// defect:bkcheck(StringViewDetect)
#include <iostream>
#include <string>
#include <string_view>

// 1、指向字符串内存被释放后，仍然使用std::string_view
void bad_01() {
    char *pStr = new char[256];
    memcpy(pStr, "Hello World", 12);
    std::string_view str(pStr, strlen(pStr));
    // ...
    delete[] pStr;
    pStr = nullptr;
    // ...
    // bad
    std::cout << "string_view: " << str << std::endl;
    // 告警压缩
    startsWith(pStr, str);
    // 告警压缩
    size_t start = 0;
    size_t end = str.find(delimiter);
    std::vector<std::string_view> result;
    // 告警压缩
    result.push_back(str.substr(start));
    // 告警压缩
    str.substr(0, prefix.size()) == prefix;
}

void bad_02() {
    char *pStr = static_cast<char *>(malloc(256));
    strcpy(pStr, "Hello World");
    std::string_view str(pStr, strlen(pStr));
    // ...
    free(pStr);
    // ...
    // bad
    std::cout << "string_view: " << str << std::endl;
    // 告警压缩
    startsWith(pStr, str);
    // 告警压缩
    size_t start = 0;
    size_t end = str.find(delimiter);
    std::vector<std::string_view> result;
    // 告警压缩
    result.push_back(str.substr(start));
    // 告警压缩
    str.substr(0, prefix.size()) == prefix;
}

// 2、local std::string 离开作用域
std::string_view bad_03() {
    std::string str("hello world");
    std::string_view sv = str;
    // bad
    return sv;
}


// 3、临时右值
std::string get_string() {
    return "a + b";
}

int f(std::string_view sv);

void bad_04() {
    // good
    int x = f(get_string()); // OK
    // bad
    std::string_view sv = get_string(); // holds a dangling pointer
}