// defect:bkcheck(StringOccupyDetect)

#include <inttypes.h>

void bad_01() {
    int d = 42;
    float f = 1.1;
    // bad
    std::printf("你好%d世界%f", d); // 数量不匹配
    // bad
    std::snprintf(str, sizeof(str), "你好%d世界%f", 1.2, f); // 类型不匹配
}

void bad_02() {
    int d = 42;
    float f = 1.1;
    const char *f1 = "你好%d世界%f";
    // bad
    std::printf(f1, d); // 数量不匹配
    f1 = "你好%d世界%f";
    // bad
    std::snprintf(str, sizeof(str), f1, 1.2, f); // 类型不匹配
}

void bad_03() {
    // bad
    std::snprintf(str, sizeof(str), "(%d,%d)", escapeString(tblsuffix).c_str(), tRefundctrlLog.new_status); // 类型不匹配
}

// 用户案例PRIu64需要替换
std::string TokenAuthorizer::UniqueSignature(const std::string& password,
                                             uint64_t timestamp,
                                             const std::string& seed) {
    char hash_buf[2048];
    // good
    snprintf(hash_buf, sizeof(hash_buf), "%s%" PRIu64 "%s", seed.c_str(),
             timestamp, password.c_str());
    std::string sig = sha256_digest(hash_buf);
    return sig;
}