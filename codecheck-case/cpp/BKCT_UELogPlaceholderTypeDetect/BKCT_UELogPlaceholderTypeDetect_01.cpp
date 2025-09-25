// defect:bkcheck(UELogPlaceholderTypeDetect)

void bad_01() {
    int32 myInt = 42;
    // bad
    UE_LOG(LogTemp, Warning, TEXT("My integer: %s"), myInt); // 错误：使用%s占位符，但传递了整数类型的参数
}

void bad_02() {
    float myFloat = 3.14f;
    // bad
    UE_LOG(LogTemp, Warning, TEXT("My float: %d"), myFloat); // 错误：使用%d占位符，但传递了浮点数类型的参数
}

void bad_03() {
    FString myString = "Hello";
    // bad
    UE_LOG(LogTemp, Warning, TEXT("My string: %d"), *myString); // 错误：使用%d占位符，但传递了字符串类型的参数
}

void bad_04() {
    int32 myInt = 42;
    // bad
    UE_LOG(LogTemp, Warning, TEXT("My int as float: %f"), myInt); // 错误：使用%f占位符，但传递了整数类型的参数
}

void bad_05() {
    // bad
    UE_LOG(LogTemp, Warning, TEXT("My string: %d"), TEXT("string")); // 错误：使用%d占位符，但传递了字符串类型的参数
}