//
// Created by wadema on 24-8-5.
//
// define:bkcheck(NameTypeMatch)

// bad
uint32_t user_uin = 0;  // 告警
// good
uint32_t head_uin = 0;  // 不告警，【微信svrkit框架历史将路由key命名为head_uin（无影响），存量代码和脚手架代码居多，通过白名单解脱】

typedef unsigned long long ulong;  // 类型定义
using uint64 = uint64_t;  // 类型别名
// good
ulong uin_1 = 0;  // 检测到实际类型符合预期，不告警
// good
uint64 uin_2 = 0;  // 检测到实际类型符合预期，不告警

// bad
uint32_t mchid = 0;  // 告警
// good
std::string cft_spid;  // 不告警

class OrderAmount {
    // bad
    int32 order_amount;  // 告警
    // bad
    int32 coupon_amount;  // 告警
    // bad
    int32 user_pay_amount;   // 告警
};

// good
OrderAmount order_amt;  // 不检测、不告警