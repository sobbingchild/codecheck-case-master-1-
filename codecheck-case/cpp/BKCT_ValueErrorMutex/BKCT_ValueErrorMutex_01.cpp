//
// Created by wadema on 24-12-6.
//
void bad_01()
{
    if (a.value())
    {
        // bad
        a.error(); //对于调用了.value()的前提下，不允许再调用.error()
    }
}

void bad_02()
{
    if (!a)
    {
        // bad
        a.value(); //对于有error的前提下，不允许再调用value
    }
}

void bad_03()
{
    if (!a && (b).value())
    {
        // bad
        a.value(); //对于有error的前提下，不允许再调用value
        // bad
        (b).error(); //对于调用了.value()的前提下，不允许再调用.error()
    }
}
