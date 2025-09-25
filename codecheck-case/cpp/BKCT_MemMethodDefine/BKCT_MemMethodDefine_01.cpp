// define:bkcheck(MemMethodDefine)

// bad
class TestA {
    public:
        TestA() {}
        void ResumeInit() {}

    private:
        int a;

};

// bad
class TestB {
    public:
        TestB() {}
        void CreateInit() {}

    private:
        int a;

};

//bad(n:2) : special method not define
class TestC {
    public:
        TestC() {}
        

    private:
        int a;

};

// good
class Good {
    public:
        Good() {}
        void ResumeInit() {}
		void CreateInit() {}
    private:
        int a;

};

//bad(n:2) : special method not define
class TestD : Good {
    public:
        TestD() {}

    private:
        int a;

};

// good
class Good2 {
    public:
        Good2() {}
        
    private:
        int a;
		void ResumeInit() {}
		void CreateInit() {}

};

//bad(n:2) : special method not define
class TestE : Good2 {
    public:
        TestE() {}

    private:
        int a;

};