//defect:bkcheck(UninitStructOrClass)

struct UninitStruct {
    int a;
};

UninitStruct global;
//目前主要是过程内，全局的还没有支持
int i = global.a;

void bad_01() {
    UninitStruct usTmp;
    //bad: uninitialized struct
    int n = usTmp.a;
}

void bad_02() {
    UninitStruct s;
    // bad
    std::cout << "(" << s.a << ")" << std::endl;
}

void bad_03() {
    UninitStruct s;
    // bad
    s.a += 1;
}

void bad_04() {
    UninitStruct s;
    // bad
    s.a -= 1;
}


struct InitStruct {
    int a;

    InitStruct() {
        a = 0;
    }
};

void good() {
    InitStruct isTmp;
    //good
    int i = isTmp.a;
}