// defect:bkcheck(ForwardNull)
#define LOG_IF(severity, condition) \
  !(condition) ? (void) 0 : google::LogMessageVoidify() & LOG(severity)

#define CHECK(condition) \
LOG_IF(FATAL, GOOGLE_PREDICT_BRANCH_NOT_TAKEN(!(condition))) \
<< "Check failed: " #condition " "

#ifndef GOOGLE_PREDICT_BRANCH_NOT_TAKEN
#if __GNUC__
#define GOOGLE_PREDICT_BRANCH_NOT_TAKEN(x) (__builtin_expect(x, 0))
#else
#define GOOGLE_PREDICT_BRANCH_NOT_TAKEN(x) x
#endif
#endif

#define LOG(severity) google::LogMessage(__FILE__, __LINE__, google::severity).stream()

void good() {
    auto *ranking_context = RankingContext::GetRankingContextFromTensorStore(ctx);
    CHECK(ranking_context);
    // good 这里是用户的误报，修复后不应该告警
    const auto *ranking_user_context = ranking_context->GetRankingUserContext();
}