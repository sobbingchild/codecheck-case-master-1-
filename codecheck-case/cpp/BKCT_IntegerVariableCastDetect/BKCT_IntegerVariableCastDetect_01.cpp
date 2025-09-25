// defect:bkcheck(IntegerVariableCastDetect)

void bad(int64 a, int32 b) {
    // bad
    if (a > b) {

    }
    uint32 c;
    uint64 d;
    // bad
    if (c != d) {

    }
    // bad
    FString::Printf(TEXT("Game_%d%ld%ld"), a, b);
    // bad
    FString::Printf(TEXT("Game_%ld"), c);
    // bad
    FString::Printf(TEXT("Game_%lld"), d);
    // good
    FString::Printf(TEXT("Game_%ld"), b);
    // good
    FString::Printf(TEXT("Game_%lld"), a);
}
