// defect:bkcheck(ResourceLeak)
#include <curl/curl.h>
#include <map>
#include <string>

void MakeReqheaders(struct curl_slist **curl_headers, const std::map<std::string, std::string> &headers) {
    *curl_headers = nullptr; // 初始化 curl_headers

    for (const auto &header: headers) {
        std::string headerStr = header.first + ": " + header.second;
        *curl_headers = curl_slist_append(*curl_headers, headerStr.c_str());
    }
}

void test1(curl_slist &slist) {

}

void test2(curl_slist **slist) {

}

void test3(curl_slist *slist) {

}


int main() {
    std::map<std::string, std::string> headers;
    headers["Content-Type"] = "application/json";
    headers["Authorization"] = "Bearer token123";

    struct curl_slist *curl_headers;
    MakeReqheaders(&curl_headers, headers);

    // 使用 curl_headers 发起请求
    // good
    curl_slist_free_all(curl_headers); // 释放 curl_headers
    return 0;
}

int bad_01() {
    std::map<std::string, std::string> headers;
    headers["Content-Type"] = "application/json";
    headers["Authorization"] = "Bearer token123";

    struct curl_slist *curl_headers;
    MakeReqheaders(&curl_headers, headers);

    // bad curl_slist_free_all(curl_headers);  未释放 curl_headers
    return 0;
}

int bad_02() {
    std::map<std::string, std::string> headers;
    headers["Content-Type"] = "application/json";
    headers["Authorization"] = "Bearer token123";

    struct curl_slist *curl_headers;
    MakeReqheaders(&curl_headers, headers);
    // 传指针地址
    test3(curl_headers);
    // bad curl_slist_free_all(curl_headers);  未释放 curl_headers
    return 0;
}

int good_01() {
    std::map<std::string, std::string> headers;
    headers["Content-Type"] = "application/json";
    headers["Authorization"] = "Bearer token123";

    struct curl_slist *curl_headers;
    MakeReqheaders(&curl_headers, headers);
    // 引用调用
    test1(*curl_headers);
    // bad 未释放 curl_headers
    return 0;
}

int good_02() {
    std::map<std::string, std::string> headers;
    headers["Content-Type"] = "application/json";
    headers["Authorization"] = "Bearer token123";

    struct curl_slist *curl_headers;
    MakeReqheaders(&curl_headers, headers);
    // 传地址
    test2(&curl_headers);
    // bad 未释放 curl_headers
    return 0;
}