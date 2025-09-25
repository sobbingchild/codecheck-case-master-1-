// define:bkcheck(FieldNotUse)

class Test {
    private:
        int a;
        // bad: field not use
        Boy b;
		// bad: field not use
        Boy c;
		// bad: field not use
        Boy d;
		// bad: field not use
        Boy e;

    public:
        void test() {
            a = 0;
            doSomething(a);
        }
};