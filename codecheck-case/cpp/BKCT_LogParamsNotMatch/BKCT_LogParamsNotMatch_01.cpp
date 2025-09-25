// defect:bkcheck(LogParamsNotMatch)

void bad_01() {
    // bad
    UE_LOG(GPSkillLog,
           Display,
           TEXT("[GPSkillAbility] [OnPlayerStateNameUpdate] Skill %s Owner %s Name %s"), *GetNameSafe(this),
           *OwnerPlayerName);// error 有3个%占位符，实际传参只有两个
    // bad
    UE_LOG(GPSkillLog,
           Display,
           TEXT("[GPSkillAbility] [OnPlayerStateNameUpdate] Skill %s Owner %s Name %s%s"), *GetNameSafe(this),
           *OwnerPlayerName);// error 有4个%占位符，实际传参只有两个
}

void bad_02() {
    // bad
    ZEN_Trace_LogMsg::debug_output(dbglevel, "hello %s world");
    // bad
    ZEN_Trace_LogMsg::debug_output(dbglevel, "hello %s world %s", a);
}

void good() {
    // good
    UE_LOG(GPSkillLog,
           Display,
           TEXT("[GPSkillAbility] [OnPlayerStateNameUpdate] Skill %s Name %s"),
           *GetNameSafe(this),
           *OwnerPlayerName);
    // good
    ZEN_Trace_LogMsg::debug_output(dbglevel, "hello %s world %s", a, b);
}