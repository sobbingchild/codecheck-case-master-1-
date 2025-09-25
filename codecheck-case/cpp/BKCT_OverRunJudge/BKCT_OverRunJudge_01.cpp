//
// Created by wadema on 2024/5/10.
//
// defect:bkcheck(OverRunJudge)

void bad_01() {
    int n[10];
    int a = rand() % 15;
    // bad
    n[a] = 3; // 变量 a 在函数上下文中没有判定，可能造成越界
}

void bad_02() {
    int *n = new int[10];
    int a = rand() % 15;
    // bad
    n[a] = 3; // 变量 a 在函数上下文中没有判定，可能造成越界
}

void bad_03() {
    int arr[10];
    int index;
    cin >> index;
    // bad
    cout << arr[index] << endl;
}

// 王者用户案例
EErrorCode CWealCondition::_ChkWealConCanUseEasyCard(CGameAccount &roAcnt, RESWEALCONDITION &rstWealRes,
                                                     COMDT_WEAL_CON_DATA_DETAIL &rstDetail,
                                                     CSPKG_USE_EASY_CARD_REQ &rstUseEasyCardReq,
                                                     uint32_t &dwNeedCardNum) {
    uint32_t dwPeriodID = rstUseEasyCardReq.m_dwPeriodID;

    if (RES_WEAL_CON_TEAM_SINGLE != rstWealRes.m_bTeamType) {
        return Err_WealEasyCard_TeamType;
    }
    // bad
    if (!CheckMaskBits<RESDT_WEALCONMASK>(rstWealRes.m_stConMask, rstWealRes.m_astConInfo[dwPeriodID].m_dwConType)) {
        return Err_WealEasyCard_ConType;
    }

    return Err_Common_Succ;
}

EErrorCode CWealCondition::_ChkWealConCanUseEasyCard(CGameAccount &roAcnt, RESWEALCONDITION &rstWealRes,
                                                     COMDT_WEAL_CON_DATA_DETAIL &rstDetail,
                                                     CSPKG_USE_EASY_CARD_REQ &rstUseEasyCardReq,
                                                     uint32_t &dwNeedCardNum) {
    uint32_t dwPeriodID = rstUseEasyCardReq.m_dwPeriodID;
    if (dwPeriodID >= rstWealRes.m_wConNum || dwPeriodID >= _countof(rstWealRes.m_astConInfo)) {
        return Err_WealEasyCard_Period;
    }

    if (RES_WEAL_CON_TEAM_SINGLE != rstWealRes.m_bTeamType) {
        return Err_WealEasyCard_TeamType;
    }
    // good 用户修复后，给dwPeriodID加了判定
    if (!CheckMaskBits<RESDT_WEALCONMASK>(rstWealRes.m_stConMask, rstWealRes.m_astConInfo[dwPeriodID].m_dwConType)) {
        return Err_WealEasyCard_ConType;
    }

    return Err_Common_Succ;
}