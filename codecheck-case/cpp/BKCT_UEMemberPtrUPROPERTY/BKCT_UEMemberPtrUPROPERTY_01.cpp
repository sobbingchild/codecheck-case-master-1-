// defect:bkcheck(UEMemberPtrUPROPERTY)
UCLASS()
class AMyClass : public AActor {
    GENERATED_BODY()

public:
    // bad
    UMyOtherClass* MyOtherObject; // 裸指针成员变量
    // bad
    class UNZSkillButtonManager* SkillButtonManager = nullptr;
};

UCLASS()
class UMyClass : public UObject {
    GENERATED_BODY()
public:

protected:
    // bad
    UMyOtherClass1* MyOtherObject1; // 裸指针成员变量

private:
    // bad
    UMyOtherClass2* MyOtherObject2; // 裸指针成员变量
};