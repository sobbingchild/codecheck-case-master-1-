// define:bkcheck(FieldInitInConstructor)

typedef int(*FN_GetBattlePassUnlock)(unsigned int64 uid, int activity_id, int stage_id);

class ActorBattlePassUnlockCond {
    ActorBattlePassUnlockCond() = default;
    ~ActorBattlePassUnlockCond() = default;

    // good
    static FN_GetBattlePassUnlock get_battlepass_unlock_fn_;
};

FN_GetBattlePassUnlock ActorBattlePassUnlockCond::get_battlepass_unlock_fn_ = nullptr;