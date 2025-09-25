package BKCT_BackwardNull


import "fmt"

func testNullCheck() {
    var str *string
    str = nil
    //bad
    fmt.Println(*str)
    if str != nil {
        fmt.Println("String is not nil")
    }
}

func anotherTest() {
    var ptr *int
    ptr = nil
    //bad
    fmt.Println(*ptr)
    if ptr != nil {
        fmt.Println("Pointer is not nil")
    }
}

func invalidAccess() {
    var arr *[]int
    arr = nil
    //bad
    fmt.Println((*arr)[0])
    if arr != nil {
        fmt.Println("Array pointer is not nil")
    }
}

func badAccess() {
    var myObj *MyStruct
    myObj = nil
    //bad
    testString := myObj.structMember
    if myObj != nil {
        fmt.Println("MyStruct pointer is not nil")
    }
}


func testNullCheckGood() {
    var str *string
    str = nil
    if str != nil {
        //good
        fmt.Println(*str)
    }
}

func anotherTestGood() {
    var ptr *int
    ptr = nil
    if ptr != nil {
        //good
        fmt.Println(*ptr)
    }
}

func validAccess() {
    var arr *[]int
    arr = nil
    if arr != nil {
        //good
        fmt.Println((*arr)[0])
    }
}

func goodAccess() {
    var myObj *MyStruct
    myObj = nil
    if myObj != nil {
        //good
        myObj.methodCall()
    }
}

type MyStruct struct{
    structMember string
}

func (m *MyStruct) methodCall() {
    fmt.Println("Method called")
}

func main() {
    // run some test functions if needed
}