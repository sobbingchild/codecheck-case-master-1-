#include <cstdint>
#include <string>
//
// Created by wadema on 24-7-2.
//
// define:bkcheck(ReturnType)
int getInt();
bool getBool();
float getFloat();

bool bad_01()
{
    int a = 1;
    if (po == nullptr)
    {
        // bad
        return 0;
    }
    // bad
    return a;
}

int bad_02()
{
    if (po == nullptr)
    {
        // bad
        return getBool();
    }
    // bad
    return getFloat();
}

void good()
{
    if (po == nullptr)
    {
    }
    // good
}


RES_ERROR_CODE CCityLogicInteraction::_CheckActorInteractionStateInvite(
    CCityActor* poActor, uint64_t ullTargetUid)
{
    //检查发起邀请者的信息
    CHECK_RET(poActor, Err_Common_Failed);

    RES_ERROR_CODE eCode = _CheckActorInteractionStateCommon(poActor, ullTargetUid);
    if (eCode != Err_Common_Succ)
    {
        // good
        return eCode;
    }
}
