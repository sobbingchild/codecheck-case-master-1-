// defect:bkcheck(ForwardNull)
# define assert(expr)                                                    \
  ((expr)                                                               \
   ? __ASSERT_VOID_CAST (0)                                             \
   : __assert_fail (__STRING(expr), __FILE__, __LINE__, __ASSERT_FUNCTION))

void good(msg::LuckyBoxDesc *src_box_desc) {
    assert(NULL != src_box_desc);
    // good 这里是用户的误报，修复后不应该告警
    uint32_t box_id = src_box_desc->box_id();
}