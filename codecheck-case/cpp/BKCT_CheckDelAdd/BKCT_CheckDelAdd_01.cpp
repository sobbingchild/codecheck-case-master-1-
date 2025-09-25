#include <cstddef>
//
// Created by wadema on 24-7-10.
//
// define:bkcheck(CheckDelAdd)
bool good_01()
{
    // good
    eErrCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_OP_ADD, vecAddResVec);
    if (Err_Common_Succ != eErrcode)
    {
        LOGERR(poAcnt, MODULE_OUTSIDEITEM, "Acnt<%s> CheckAndModify eErrcode %d",
               poAcnt->GetLogstr(), eErrcode);
        return eErrCode;
    }
    // good step2.删除背包里面的道具
    eErrcode = CResourcesMgr::Instance().DelResList(poAcnt, VeCDeIReS,
                                                    ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM);
    if (Err_Common_Succ != eErrCode)
    {
        LOGTRACE(poAcnt, MODULE_OUTSIDEITEM, "outsideItemId %d DelResList fail,",
                 refonecfgoutsideItem.m_i0utsideItemId);
        return eErrcode;
    }

    // good step3.增加宝可梦资源
    eErrCode = CResourcesMgr::Instance().AddResList(poAcnt, VeCAddRESVEC,
                                                    ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM,
                                                    STAddResParam(false, NULL));
    if (Err_Common_Succ != eErrcode)
    {
        LOGERR(pOAcnt, MODULE_OUTSIDEITEM, "Acnt<%s> AddResList eErrcode %d", poAcnt->GetLogstr(),
               eErrcode);
        return eErrcode;
    }
    return Err_Common_Succ;
}

void good_02()
{
    // good step1
    CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_OP_ADD, vecAddResVec);
    // good step2
    CResourcesMgr::Instance().DelResList(poAcnt, VeCDeIReS,
                                         ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM);
    // good step3
    CResourcesMgr::Instance().AddResList(poAcnt, VeCAddRESVEC,
                                         ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM,
                                         STAddResParam(false, NULL));
}

void bad_01()
{
    // bad
    CResourcesMgr::Instance().DelResList(poAcnt, VeCDeIReS,
                                         ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM);
}

void bad_02()
{
    // bad
    CResourcesMgr::Instance().AddResList(poAcnt, VeCAddRESVEC,
                                         ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM,
                                         STAddResParam(false, NULL));
}

void bad_03()
{
    CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_OP_ADD, vecAddResVec);
    // bad
    CResourcesMgr::Instance().AddResList(poAcnt, VeCAddRESVEC,
                                         ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM,
                                         STAddResParam(false, NULL));
}

void bad_04()
{
    // bad
    CResourcesMgr::Instance().DelResList(poAcnt, VeCDeIReS,
                                         ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM);
    CResourcesMgr::Instance().AddResList(poAcnt, VeCAddRESVEC,
                                         ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM,
                                         STAddResParam(false, NULL));
}
