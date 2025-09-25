// defect:bkcheck(UnusedValue)
// 用户案例，需要消除lambda引用捕获的场景所造成的误报
MQRequestHandler::Result BanPaySendSmsHandler::Process(unsigned int uin,
                                                       mmpaymultisetcashierasyncmq::BanPaySendSmsReq
                                                       & tReq)
{
    unsigned int iUin = tReq.uin();
    const string& wx_ticket = tReq.wx_ticket();
    int64_t total_fee = 0;
    std::string out_trade_no;
    std::string verify_code;
    MQRequestHandler::Result result = RES_ERROR;
    MMPayAIOpsReporter interface_call_reporter;
    interface_call_reporter.SetBizId(2872);
    interface_call_reporter.Set("uin", iUin);

    int ret = 0;
    auto report_guard = dry::MakeScopedGuard([&]
    {
        ReportSmsRecord(uin, total_fee, out_trade_no.c_str(), wx_ticket.c_str(),
                        verify_code.c_str(), result);
        interface_call_reporter.SetBizId(2872);
        interface_call_reporter.SetErrCode(ret);
        interface_call_reporter.Set("out_trade_no", out_trade_no);
        interface_call_reporter.Report();
    });

    if (wx_ticket.length() < 8)
    {
        OssAttrInc(64746, 38, 1);
        MTPLOG_WARN_STREAM("Invalid WxTicket") << MTPLOG_PAIRS(iUin, wx_ticket);
        result = RES_FALSE;
        // good
        ret = comm::ERR_APPPAY_MMPAYCASHIERASYNCMQ_INVALID_REQ_KEY;
        return result;
    }

    const std::string& desverifycode = tReq.verify_code();
    if ("general_sms_wx_pure_sms" == desverifycode)
    {
        // 目前的监控上看，不支持此模板消息
        OssAttrInc(64746, 23, 1);
        MTPLOG_WARN_STREAM("Invalid VerifyCode") << MTPLOG_PAIRS(iUin, wx_ticket);
        result = RES_FALSE;
        // good
        ret = comm::ERR_APPPAY_MMPAYCASHIERASYNCMQ_INVALID_VERIFY_CODE;
        return result;
    }

    // 存量债务，这个key应该进统一加解密，先备注，后面排期迁移
    static const string kVerifyCodeKey = "123456";
    mmpaycommtools::UnDes3Str(kVerifyCodeKey.c_str(), desverifycode.c_str(), verify_code);

    ret = LoadSmsContent(iUin, wx_ticket, total_fee, out_trade_no);
    if (ret != 0)
    {
        return ret == comm::ERR_APPPAY_MMPAYCASHIERASYNCMQ_INVALID_REQ_KEY ? RES_FALSE : RES_ERROR;
    }

    std::string yuan =
        fmt::format("{:.2f}", static_cast<double>(total_fee) / 100.00);

    time_t timenow = time(nullptr);
    char timestr[32] = {0};
    MMPayUtils::Time2String(timestr, sizeof(timestr), timenow);

    ret = SendVerifyCodeForPayBusiSmsSvr(iUin, wx_ticket, yuan, timestr, verify_code);
    result = (ret == 0 ? RES_TRUE : RES_ERROR);
    return result;
}
