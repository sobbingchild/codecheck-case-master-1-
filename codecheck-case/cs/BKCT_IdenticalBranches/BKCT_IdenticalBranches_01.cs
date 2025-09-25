using System;

public class BKCT_IdenticalBranches_01
{
    void bad_01(int x, int y, int z)
    {
        // bad
        if (x == 2)
        {
            y = 32;
            z = y * 2;
        }
        else
        {
            y = 32;
            z = y * 2;
        }
    }

    void bad_02(bool condition)
    {
        // bad
        if (condition)
        {
            Console.WriteLine("Repeated code");
        }
        else
        {
            Console.WriteLine("Repeated code");
        }
    }

    void good_01(bool condition)
    {
        // good
        if (condition)
        {
            Console.WriteLine("Repeated code");
        }
        else
        {
            Console.WriteLine("Another different branch");
        }
    }
}