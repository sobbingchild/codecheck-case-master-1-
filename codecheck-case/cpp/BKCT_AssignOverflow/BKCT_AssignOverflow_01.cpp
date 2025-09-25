//
// Created by wadema on 24-8-8.
//
// define:bkcheck(AssignOverflow)
void bad_01()
{
    int a = 1;
    long long b = 5;
    // bad
    a = b;
    // good
    b = a;
}

void bad_02()
{
    float a = 1.1;
    long double b = 5.5;
    // bad
    a = b;
    // good
    b = a;
}

void bad_0304()
{
    int a = 1;
    float b = 1.1;
    // bad
    a = b;
    // bad
    b = a;
}
