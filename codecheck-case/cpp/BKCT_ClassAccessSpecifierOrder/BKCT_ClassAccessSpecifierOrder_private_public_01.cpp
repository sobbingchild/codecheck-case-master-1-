
// defect:bkcheck(BKCT_ClassAccessSpecifierOrder)

class A {
private:
    int m_a;
public:
    // bad
    int m_b;
};

class B {
protected:
	int m_c;
public:
    // bad	
    int m_b;
private:
    // good
    int m_a;
};

class C {
public:
    int m_b;
private:
    // good
    int m_a;
public:
    // bad
    int m_c;
};

class D {
protected:
    int m_a;
public:
    // bad
    int m_b;
};