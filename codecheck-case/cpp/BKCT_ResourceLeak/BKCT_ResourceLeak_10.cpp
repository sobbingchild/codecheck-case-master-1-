// defect:bkcheck(ResourceLeak)


int good()
{
    // 排除该智能指针类型
    tars::TC_AutoPtr<QueueItem> pstMsg = new QueueItem();
    pstMsg->iTime = TNOW;
    pstMsg->params.put("TNotifyResponseApply", notify);
    pstMsg->current = current;
    // good
    return 0;
}
