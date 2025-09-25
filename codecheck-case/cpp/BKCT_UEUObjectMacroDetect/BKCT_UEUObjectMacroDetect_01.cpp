// defect:bkcheck(UEUObjectMacroDetect)

// bad(n:2) 缺少UCLASS()宏和GENERATED_BODY()宏
class UMyObject : public UObject
{

public:
    UPROPERTY(EditAnywhere, Category = "MyObject")
    int32 MyIntProperty;

    UPROPERTY(EditDefaultsOnly, Category = "MyObject")
    FString MyStringProperty;
};

// bad(n:2) 缺少UCLASS()宏和GENERATED_BODY()宏
class AMyActor : public AActor
{

public:
    UPROPERTY(EditAnywhere, Category = "MyActor")
    float MyFloatProperty;

    UPROPERTY(EditDefaultsOnly, Category = "MyActor")
    UStaticMeshComponent* MyMeshComponent;

    UPROPERTY(BlueprintReadOnly, Category = "MyActor")
    FString MyStringProperty;
};