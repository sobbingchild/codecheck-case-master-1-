// defect:bkcheck(ForwardNull)

#define CHECK(x)                                           \
  if (!(x))                                                \
    dmlc::LogMessageFatal(__FILE__, __LINE__).stream()     \
      << "Check failed: " #x << ": "

void good(msg::LuckyBoxDesc *src_box_desc) {
    CHECK(NULL != src_box_desc);
    // good
    uint32_t box_id = src_box_desc->box_id();
}