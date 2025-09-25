// defect:bkcheck(NonPodMemSetDetect)

typedef std::vector <string> AliasVector;

struct Test_Struct {
    AliasVector aliasVector;
};
Test_Struct test_struct;
// bad
STRUCT_MEMSET(test_struct);

void bad_01() {
    Test_Struct test_struct1;
    // bad
    STRUCT_MEMSET(test_struct1);
}

void bad_02(Test_Struct test_struct2) {
    // bad
    STRUCT_MEMSET(test_struct2);
}

void bad_03(Test_Struct &test_struct3) {
    // bad
    STRUCT_MEMSET(test_struct3);
}