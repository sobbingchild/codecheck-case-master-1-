//
// Created by wadema on 2024/6/12.
//
// defect:bkcheck(NoTSharedPtrCast)

class MyClass {
private:
    // bad
    TArray <TSharedPtr<UStringTable>> StringTableCached1;
    // bad
    TArray <TWeakPtr<UStringTable>> StringTableCached2;
    // bad
    TArray <TUniquePtr<UStringTable>> StringTableCached3;
    // bad
    TSharedPtr <UStringTable> StringTableCached4;
    // good
    TArray<UStringTable *> s;
    // good
    TSharedPtr <UEdGraphSchema_K2::FPinTypeTreeInfo> a;
    // good
    TSharedPtr <uint8> b;
};
