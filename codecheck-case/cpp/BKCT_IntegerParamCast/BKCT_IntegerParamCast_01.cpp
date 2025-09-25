// defect:bkcheck(IntegerParamCast)

void f1(signed char a) {}

void f2(unsigned char a) {}

void f3(short a) {}

void f4(short int a) {}

void f5(signed short a) {}

void f6(signed short int a) {}

void f7(unsigned short a) {}

void f8(unsigned short int a) {}

void f9(int a) {}

void f10(signed a) {}

void f11(signed int a) {}

void f12(unsigned a) {}

void f13(unsigned int a) {}

void f14(long a) {}

void f15(long int a) {}

void f16(signed long a) {}

void f17(signed long int a) {}

void f18(unsigned long a) {}

void f19(unsigned long int a) {}

void f20(long long a) {}

void f21(long long int a) {}

void f22(signed long long a) {}

void f23(signed long long int a) {}

void f24(unsigned long long a) {}

void f25(unsigned long long int a) {}


void bad_01_09() {
    signed char a1 = 1;
    // good
    f1(a1);

    unsigned char a2 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f1(a2);

    short a3 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f2(a3);
    short int a4 = 1;
    // good
    f3(a4);
    signed short a5 = 1;
    // good
    f4(a5);
    signed short int a6 = 1;
    // good
    f5(a6);

    unsigned short a7 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f6(a7);
    unsigned short int a8 = 1;
    // good
    f7(a8);

    int a9 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f8(a9);
    signed a10 = 1;
    // good
    f9(a10);
    signed int a11 = 1;
    // good
    f10(a11);

    unsigned a12 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f11(a12);
    unsigned int a13 = 1;
    // good
    f12(a13);

    long a14 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f13(a14);
    long int a15 = 1;
    // good
    f14(a15);
    signed long a16 = 1;
    // good
    f15(a16);
    signed long int a17 = 1;
    // good
    f16(a17);

    unsigned long a18 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f17(a18);
    unsigned long int a19 = 1;
    // good
    f18(a19);

    long long a20 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f19(a20);
    long long int a21 = 1;
    // good
    f20(a21);
    signed long long a22 = 1;
    // good
    f21(a22);
    signed long long int a23 = 1;
    // good
    f22(a23);

    unsigned long long a24 = 1;
    // bad 可能发生隐式转换导致精度丢失
    f23(a24);
    unsigned long long int a25 = 1;
    // good
    f24(a25);

}