
// defect:bkcheck(DuDefine)

void bad1(bool flag) {
    if (flag) {
        // bad: redefine num
        int num = 2;
    }
	int num = 1;
}

void bad2(bool flag) {
    int num = 1;
    if (flag) {
        // bad: redefine num
        int num = 2;
    }
}


void bad3(bool flag) {
    if (flag) {
        int num = 2;
		if (flag) {
			// bad: redefine num
			int num = 2;
		}
    }
}

void bad4(bool flag, bool flag2) {
    int num = 1;
    if (flag) {
		if (flag2) {
        // bad: redefine num
        int num = 2;
		}
    }
}

TEST_F(Audit_busi_shuntTest, NoShunt) {
  // 获取规则
  mmpaymchpa::operating::v2::BusiRule busi_rule(kBusinessId, kSubBusinessType, this->profiles_);
  auto [ret, msg] = busi_rule.Build();

  // EXPECT_EQ
  ASSERT_EQ(ret, 0) << msg;

  // good
  auto [err_t_info, flow_info] = busi_rule.GetFlowRuleByBusiInfo();
  ASSERT_EQ(std::get<0>(err_t_info), 0) << std::get<1>(err_t_info);

  ASSERT_EQ(flow_info.index(), 1);
  EXPECT_EQ(std::get<1>(flow_info).op_flow_rule->GetRuleName(), "test_for_desc");
}