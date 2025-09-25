//
// Created by wadema on 24-8-6.
//
// define:bkcheck(NameTypeMatch)
#include <iostream>
#include <cstdint>

using uint64 = uint64_t; // 类型别名

// 测试代码
void testVariables()
{
    // good 变量名包含 "uin" 且类型为 uint64_t，符合规则
    uint64_t user_uin = 123456789;

    // good 变量名包含 "route_uin" 且类型为 uint32_t，但命中过滤关键字，不做告警
    uint32_t route_uin = 123456789;

    // good 变量名包含 "head_uin" 且类型为 unsigned int，但命中过滤关键字，不做告警
    unsigned int head_uin = 987654321;

    // good 变量名包含 "RouteUin" 且类型为 unsigned int，但命中过滤关键字，不做告警
    unsigned int dwRouteUin = 987654321;

    // good 变量名包含 "iHeadUin" 且类型为 uint32_t，但命中过滤关键字，不做告警
    uint32_t iHeadUin = 123456789;

    // bad 变量名包含 "uin" 且类型为 uint32_t，不符合规则，告警
    uint32_t uin = 123456789;

    // bad 变量名包含 "uin" 且类型为 int64_t，不符合规则，告警
    int64_t uin1 = 123456789;

    // good 检测到实际类型符合预期，不告警
    uint64 uin_2 = 0;

    // good 变量名包含 "mchid" 且类型为 unsigned long long，符合规则
    unsigned long long mchid = 987654321;

    // bad 变量名包含 "mchid" 且类型为 unsigned int，不符合规则，告警
    unsigned int mchid1 = 987654321;

    // good 变量名包含 "mchcode" 且类型为 string，并非基础类型，不做扫描，不告警
    std::string mchcode = "123456789";

    // good 变量名包含 "mch_code" 且类型为 unsigned long long，符合规则
    unsigned long long mch_code = 987654321;

    // good 变量名包含 "partner" 且类型为 uint64_t，符合规则
    uint64_t partner = 123456789;

    // good 变量名包含 "partnerid" 且类型为 unsigned long long，符合规则
    unsigned long long partnerid = 987654321;

    // good 变量名包含 "partner_id" 且类型为 unsigned long long int，符合规则
    unsigned long long int partner_id = 987654321;

    // good 变量名包含 "spid" 且类型为 uint64_t，符合规则
    uint64_t spid = 123456789;

    // good 变量名包含 "sp_id" 且类型为 unsigned long long，符合规则
    unsigned long long sp_id = 987654321;

    // good 变量名包含 "tenpay_merchant_no" 且类型为 uint64_t，符合规则
    uint64_t tenpay_merchant_no = 123456789;

    // good 变量名包含 "amount" 且类型为 double，符合规则
    double total_amount = 1234.56;

    // good 变量名包含 "fee" 且类型为 long double，符合规则
    long double transaction_fee = 78.90;

    // good 变量名包含 "balance" 且类型为 int64_t，符合规则
    int64_t account_balance = 1000000;

    // good 变量名包含 "deposit" 且类型为 long long，符合规则
    long long initial_deposit = 500000;

    // bad 变量名包含 "fee" 且类型为 uint64_t，不符合规则，告警
    uint64_t fee = 123456789;

    // good 变量名包含 "amount" 且类型为 double，符合规则
    double amount = 1234.56;

    // good 变量名包含 "amt" 且类型为 long double，符合规则
    long double amt = 78.90;

    // good 变量名包含 "yuan" 且类型为 long long，符合规则
    long long yuan = 500000;

    // good 变量名包含 "money" 且类型为 long long int，符合规则
    long long int money = 987654321;

    // good 变量名包含 "balance" 且类型为 double，符合规则
    double balance = 1234.56;

    // good 变量名包含 "deposit" 且类型为 long double，符合规则
    long double deposit = 78.90;
    // good
    OrderAmount order_amt; // 不检测、不告警
}

int main()
{
    testVariables();
    return 0;
}
