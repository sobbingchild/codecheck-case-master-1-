// defect:bkcheck(SameInit)

void good() {
    // 这是用户宏替换后的内容，虽然行号相邻，但是这里不应该告警
    switch (0) case 0: default: if (const ::testing::AssertionResult gtest_ar_ = ::testing::AssertionResult(m.Matches(a))) ; else ::testing::internal::AssertHelper(::testing::TestPartResult::kNonFatalFailure, "D:\\bkcheckcode\\yaml-cpp\\test\\gmock-1.7.0\\test\\gmock-matchers_test.cc", 1078, ::testing::internal::GetBoolAssertionFailureMessage( gtest_ar_, "m.Matches(a)", "false", "true").c_str()) = ::testing::Message()                        ;
    switch (0) case 0: default: if (const ::testing::AssertionResult gtest_ar_ = ::testing::AssertionResult(!(m.Matches(b)))) ; else ::testing::internal::AssertHelper(::testing::TestPartResult::kNonFatalFailure, "D:\\bkcheckcode\\yaml-cpp\\test\\gmock-1.7.0\\test\\gmock-matchers_test.cc", 1079, ::testing::internal::GetBoolAssertionFailureMessage( gtest_ar_, "m.Matches(b)", "true", "false").c_str()) = ::testing::Message()                         ;
}
