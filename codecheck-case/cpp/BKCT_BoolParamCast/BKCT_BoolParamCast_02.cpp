// defect:bkcheck(BoolParamCast)

// 用户案例，需要排除修饰符重载函数
#include <string>

std::string valueToString(int value)
{
    return "1";
}

TestResult& TestResult::operator<<(Json::Int64 value) {
    // good
    return addToLastFailure(valueToString(value));
}

TestResult& TestResult::operator<<(Json::UInt64 value) {
    // good
    return addToLastFailure(valueToString(value));
}

TestResult& TestResult::operator<<(bool value) {
    return addToLastFailure(value ? "true" : "false");
}