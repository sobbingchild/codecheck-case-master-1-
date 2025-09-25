//
// Created by wadema on 24-12-11.
//
#include <iostream>

class Simple
{
    int a = 0;
    char b = 0;
    double c = 0;
};

class Base
{
    Simple simple[8][8] = {};
};

class Derived : public Base
{
    char derivedValue = 0;
    double derivedDouble = 0;
    Simple s;
};

int bad_01()
{
    // good
    Simple s = Simple();
    // bad
    Base b = Base();
    // bad
    Derived d = Derived();
    // good
    Derived* dp = &d;
    return 0;
}
