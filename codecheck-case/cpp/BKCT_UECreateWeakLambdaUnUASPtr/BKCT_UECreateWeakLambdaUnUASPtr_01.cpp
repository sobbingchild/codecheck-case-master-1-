// defect:bkcheck(UECreateWeakLambdaUnUASPtr)

void bad_01() {
    UObject *MyObject = NewObject<UObject>();

    // bad 错误示例：Lambda函数参数以U开头的指针命名
    CreateWeakLambda([MyObject](UObject *UPointer) {
        // 在Lambda函数中使用以U开头的指针参数
        // 这将导致编译错误，因为参数命名以U开头的指针是不允许的
    });

    // good 正确示例：将UObject*复制到局部变量中，然后在Lambda函数中使用局部变量
    CreateWeakLambda([MyObject]() {
        UObject *LocalObject = MyObject;
        // 在Lambda函数中使用局部变量
        // 这样可以确保在Lambda函数执行期间，指针仍然有效
    });
}

void bad_02() {
    // bad 错误案例1：参数以U开头的指针命名
    CreateWeakLambda([](UObject *UPointer) {
        // 在Lambda函数中使用以U开头的指针参数
        // 这违反了规则，应该报错
    });

    // bad 错误案例2：参数以A开头的指针命名
    CreateWeakLambda([](AActor *APointer) {
        // 在Lambda函数中使用以A开头的指针参数
        // 这违反了规则，应该报错
    });

    // bad 错误案例3：参数以S开头的指针命名
    CreateWeakLambda([](USceneComponent *SPointer) {
        // 在Lambda函数中使用以S开头的指针参数
        // 这违反了规则，应该报错
    });

    // good 正确案例：参数不以U、A、S开头的指针命名
    CreateWeakLambda([](UObject *ObjectPointer) {
        // 在Lambda函数中使用不以U、A、S开头的指针参数
        // 这符合规则，不应该报错
    });
}