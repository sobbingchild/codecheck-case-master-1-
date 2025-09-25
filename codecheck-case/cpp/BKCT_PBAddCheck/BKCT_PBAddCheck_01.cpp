//
// Created by wadema on 24-6-21.
//
// defect:bkcheck(PBAddCheck)

void good() {
    if (rstRsp.is_playerlist_full()) {
        return;
    }
    // good
    pbCOMDT_SEARCH_PLAYER_RESULT *poResult = rstRsp.add_playerlist();
}

void bad_01() {
    // bad
    rstRsp.add_playerlist();
}
void bad_02() {
    if (rstRsp1.is_playerlist_full()) {
        return;
    }
    // bad
    rstRsp.add_playerlist();
}

// 用户案例
void CGameLogicFriend::_SearchFromAiAndShortId(CCoroData *poCoroData, const pbCSPkg &rstCSPkg, pbSCSearchPlayerRsp &rstRsp, bool &bFoundInShortId)
{
    CHECK_VOID(poCoroData);
    CGameAccount *poAcnt = poCoroData->GetGameAcnt();
    CHECK_VOID(poAcnt);

    // 优先去拉一下超强人机AI信息
    _SearchAIByFightHistoryRecord(poCoroData, rstCSPkg, rstRsp);

    uint64_t ullUid = 0;
    bFoundInShortId = false;
    // 根据短ID查找
    RES_ERROR_CODE eCode = CGameLogicLogin::Instance().FindIDByShortId(poCoroData, rstRsp.searchstring().c_str(), ullUid);
    if (Err_Common_Succ == eCode)
    {
        LOGTRACE(poCoroData->GetUid(), MODULE_FRIEND, "Friend@RCD Acnt<%s> match search string %s by shortid, uid:%lu", poAcnt->GetLogStr(), rstRsp.searchstring().c_str(), ullUid);

        pbCOMDT_SEARCH_PLAYER_RESULT rstResult;
        eCode = SearchByUID(poCoroData, ullUid, rstResult, true);
        if (Err_Common_Succ == eCode)
        {
            rstResult.set_baseontype((int8_t)ENM_SEARCH_BASE_ON_TYPE_SHORTID);
            if (!rstRsp.is_playerlist_full())
            {
                // good
                *rstRsp.add_playerlist() = rstResult;
            }

            bFoundInShortId = true;
        }
    }
    else
    {
        LOGTRACE(poCoroData->GetUid(), MODULE_FRIEND, "Friend@RCD Acnt<%s> fail match search string %s by shortid", poAcnt->GetLogStr(), rstRsp.searchstring().c_str());
    }

    WriteTlogSecSearchFlow(poAcnt, ENM_TLOG_SEC_SEARCH_TYPE_ROLE_SHORTID, rstRsp.searchstring());

    return;
}