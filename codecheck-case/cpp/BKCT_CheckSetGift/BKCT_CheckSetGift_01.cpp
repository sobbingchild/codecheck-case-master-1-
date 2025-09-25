//
// Created by wadema on 24-7-5.
//
// define:bkcheck(CheckSetGift)

bool good()
{
    bool bDropExistTrainItem = _CheckDropExistTrainItem(poAcnt, vecAddRes);
    // good 第一步CheckAndModify
    eErrorCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_0P_ADD, vecAddRes,
                                                          bDropExistTrainItem);
    // good 第二步_SetLevelGiftBit
    if (!_SetLevelGiftBit(poAcnt, iGiftFlag, eGiftType))
    {
        LOGERR(pOAcnt, MODULE_ACNT_LEVEL, "_SetLevelGiftBit fail, eErrorcode<%d>", eErrorcode);
        return false;
    }
    // good 第三步_WriteGetAcntGiftTlog
    _WriteGetAcntGiftTlog(poAcnt, iRewardExp, iGiftFlag, eGiftType);
    STAddResParam stResParam(true, &strBillNo);
    // good 第四步AddResList
    eErrorCode = CResourcesMgr::Instance().AddResList(poAcnt, vecAddRes, eReason, stResParam);
    // good
    return true;
}

bool bad_01()
{
    bool bDropExistTrainItem = _CheckDropExistTrainItem(poAcnt, vecAddRes);
    // 第一步CheckAndModify
    eErrorCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_0P_ADD, vecAddRes,
                                                          bDropExistTrainItem);
    // 第二步_SetLevelGiftBit
    if (_SetLevelGiftBit(poAcnt, iGiftFlag, eGiftType))
    {
        LOGERR(pOAcnt, MODULE_ACNT_LEVEL, "_SetLevelGiftBit fail, eErrorcode<%d>", eErrorcode);
        // bad 缺少3、4步
        return false;
    }
    // 第三步_WriteGetAcntGiftTlog
    _WriteGetAcntGiftTlog(poAcnt, iRewardExp, iGiftFlag, eGiftType);
    STAddResParam stResParam(true, &strBillNo);
    // 第四步AddResList
    eErrorCode = CResourcesMgr::Instance().AddResList(poAcnt, vecAddRes, eReason, stResParam);
    return true;
}

bool bad_02()
{
    bool bDropExistTrainItem = _CheckDropExistTrainItem(poAcnt, vecAddRes);
    // 第一步CheckAndModify
    eErrorCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_0P_ADD, vecAddRes,
                                                          bDropExistTrainItem);
    // 第二步_SetLevelGiftBit
    if (!_SetLevelGiftBit(poAcnt, iGiftFlag, eGiftType))
    {
        LOGERR(pOAcnt, MODULE_ACNT_LEVEL, "_SetLevelGiftBit fail, eErrorcode<%d>", eErrorcode);
        return false;
    }
    // 第三步_WriteGetAcntGiftTlog
    _WriteGetAcntGiftTlog(poAcnt, iRewardExp, iGiftFlag, eGiftType);
    STAddResParam stResParam(true, &strBillNo);
    // eErrorCode = CResourcesMgr::Instance().AddResList(poAcnt, vecAddRes, eReason, stResParam);
    // bad 缺少第四步
    return true;
}

bool bad_03()
{
    bool bDropExistTrainItem = _CheckDropExistTrainItem(poAcnt, vecAddRes);
    // eErrorCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_0P_ADD, vecAddRes,
    //                                                       bDropExistTrainItem);
    // bad 缺少第一步
    if (!_SetLevelGiftBit(poAcnt, iGiftFlag, eGiftType))
    {
        LOGERR(pOAcnt, MODULE_ACNT_LEVEL, "_SetLevelGiftBit fail, eErrorcode<%d>", eErrorcode);
        return false;
    }
    // 第三步_WriteGetAcntGiftTlog
    _WriteGetAcntGiftTlog(poAcnt, iRewardExp, iGiftFlag, eGiftType);
    STAddResParam stResParam(true, &strBillNo);
    // 第四步AddResList
    eErrorCode = CResourcesMgr::Instance().AddResList(poAcnt, vecAddRes, eReason, stResParam);
    return true;
}

void bad_04()
{
    bool bDropExistTrainItem = _CheckDropExistTrainItem(poAcnt, vecAddRes);
    // 第一步CheckAndModify
    eErrorCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_0P_ADD, vecAddRes,
                                                          bDropExistTrainItem);
    // 第二步_SetLevelGiftBit
    _SetLevelGiftBit(poAcnt, iGiftFlag, eGiftType);
    // 第三步_WriteGetAcntGiftTlog
    _WriteGetAcntGiftTlog(poAcnt, iRewardExp, iGiftFlag, eGiftType);
    STAddResParam stResParam(true, &strBillNo);
    // eErrorCode = CResourcesMgr::Instance().AddResList(poAcnt, vecAddRes, eReason, stResParam);
    // bad 缺少第四步
}
