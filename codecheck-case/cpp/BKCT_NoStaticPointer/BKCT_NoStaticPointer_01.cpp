//
// Created by wadema on 2024/6/11.
//
// defect:bkcheck(NoStaticPointer)

void bad_0102() {
    // bad
    static UObject *StaticObjInst1;
    // bad
    static UObject *StaticObjInst2 = nullptr;
}

void bad_0304() {
    // bad
    static AObject *StaticObjInst1;
    // bad
    static AObject *StaticObjInst2 = nullptr;
}