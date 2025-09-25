// defect:bkcheck(ForwardNull)
#define assert(__e) ((__e) ? (void)0 : __assert_fail(#__e, __FILE__, __LINE__, __PRETTY_FUNCTION__))

void good(msg::LuckyBoxDesc *src_box_desc) {
    assert(NULL != src_box_desc);
    // good 这里是用户的误报，修复后不应该告警
    uint32_t box_id = src_box_desc->box_id();
}