//
// Created by wadema on 24-11-12.
//
// define:bkcheck(ErrorInvokerDetect)

void bad()
{
    if (!a)
    {
        // bad
        b.error();
    }
}

void good()
{
    if (!a)
    {
        // good
        a.error();
    }
}

void good_02()
{
    if (!a)
    {
        if (auto ret = foo(); !b)
        {
            // good
            b.error();
        }
    }
}

void good_03()
{
    if (!a)
    {
        if (!(ret))
        [[unlikely]]
        {
            // good
            (ret).error();
        }
    }
}

void good_04()
{
    if (!a)
    {
        // good
        if (!add_ret && foo(add_ret.error().get_code()))
        {
            // good
            add_ret.error();
        }
    }
}

void good_05()
{
    if (!a)
    {
        if (false)
        {
            // good
            b.error();
        }
        if (!(ret))
        [[unlikely]]
        {
            // good
            (ret).error();
        }
    }
}
