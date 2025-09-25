// define:bkcheck(StructConstructor)

// bad: struct no constructor
struct Test1 {
    private:
        int a;
};

// bad: struct no constructor
struct Test2 {
    private:
        int a;
        void test() {}
};

// bad: struct no constructor
struct Test3 {
    public:
        int a;
};

// bad: struct no constructor
struct Test4 {
    public:
        int a;
        void test() {}
};
