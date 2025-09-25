//
// Created by wadema on 2024/5/16.
//
// define:bkcheck(DirectNullPointer)
#include <iostream>
#include <vector>
#include <algorithm>

// 语句中的三元表达式的场景
AActorSetProxy* AActorSetProxy::LevelActor2ActorS(AActor* ActorInLevel)
{
    // good
    UE_LOG(Log, Log, TEXT("LevelActor2."),
           ActorInLevel == nullptr&&a==0 ? TEXT("NO") : *ActorInLevel->Get(),
           ActorInLevel == nullptr || ActorInLevel->GetClass() == nullptr
               ? TEXT("NO")
               : *ActorInLevel->GetClass()->Get());
    return SetProxy;
}

void good_01()
{
    // good
    foo(ActorInLevel->GetClass() == nullptr ? 0 : *ActorInLevel->GetClass()->Get());
}

// 语句中的逻辑表达式前后
void good_02()
{
    // good
    bool a = !AIC->Get() || AIC->Get()->GetClass() != AICo;
}
