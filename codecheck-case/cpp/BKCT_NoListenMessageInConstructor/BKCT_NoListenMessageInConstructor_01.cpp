// defect:bkcheck(NoListenMessageInConstructor)

AActor::AActor() {
    // bad
    FGMMessageHelper::ListenMessage(MSGKEY("Avatar.Setup.Equip"), this, &AActor::LoadContextBegin);  //error可能引发崩溃
    // bad
    FGMMessageHelper::ListenObjectMessage(GetOwner(), MSGKEY("Avatar.Setup.Equip"), this,
                                          &AActor::LoadContextBegin);  //error可能引发崩溃
}

AActor::AActor2() {
    // bad
    use(FGMMessageHelper::ListenMessage(MSGKEY("Avatar.Setup.Equip"), this, &AActor::LoadContextBegin));
    // bad
    use(FGMMessageHelper::ListenObjectMessage(GetOwner(), MSGKEY("Avatar.Setup.Equip"), this,
                                              &AActor::LoadContextBegin));
}