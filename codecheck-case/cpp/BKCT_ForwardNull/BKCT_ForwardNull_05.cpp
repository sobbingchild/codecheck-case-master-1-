// defect:bkcheck(ForwardNull)

#define assert(expression) (void)( (!! (expression)) || (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), __LINE__), 0) )

void good(msg::LuckyBoxDesc *src_box_desc) {
    assert(NULL != src_box_desc);
    // good 这里理论上不会告警，因为assert替换后没有判断语句
    uint32_t box_id = src_box_desc->box_id();
}