//
// Created by wadema on 24-8-7.
//

// define:bkcheck(CheckDelAddX)
void good_01()
{
    RES_ERROR_CODE eCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_OP_DEL, vecDelRes);
    if (Err_Common_Succ != eCode)
    {
        return eCode;
    }

    eCode = CResourcesMgr::Instance().DelResList(poAcnt, VecDeIReS,
                                                 ENM_RESOURCE_CHG_REASON_USEOUTSIDEITEM);
    if (Err_Common_Succ != eCode)
    {
        return eCode;
    }
    //能量容量逻辑
    if (0 < iPayEnergycapacity)
    {
        // good
        if (!CGameLogicEnergy::Instance().
            AddPayEnergyCapacity(poAcnt, iPayEnergyCapacity * iUseCnt))
        {
        }
    }
}

void bad()
{
    RES_ERROR_CODE eCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_OP_DEL, vecDelRes);
    if (Err_Common_Succ != eCode)
    {
        return eCode;
    }
    //能量容量逻辑
    if (0 < iPayEnergycapacity)
    {
        // bad
        if (!CGameLogicEnergy::Instance().
            AddPayEnergyCapacity(poAcnt, iPayEnergyCapacity * iUseCnt))
        {
        }
    }
}

void good_02()
{
    RES_ERROR_CODE eCode = CResourcesMgr::Instance().CheckAndModify(poAcnt, ENM_OP_DEL, vecDelRes);
    if (Err_Common_Succ != eCode)
    {
        return eCode;
    }
    // 有SetGiftBit，说明不是资源变更函数
    _SetLevelGiftBit(poAcnt, iGiftFlag, eGiftType);
    //能量容量逻辑
    if (0 < iPayEnergycapacity)
    {
        // good 不需要告警
        if (!CGameLogicEnergy::Instance().
            AddPayEnergyCapacity(poAcnt, iPayEnergyCapacity * iUseCnt))
        {
        }
    }
}
