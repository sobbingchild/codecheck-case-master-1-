using System;

public class BKCT_DevideByZero_01
{
    public static void Bad_01()
    {
        int a = 0;

        int b = 1 / a;
    }

    public static void Bad_02()
    {

        int b = 1 / 0;
    }

    public static void Bad_03()
    {
        int a = 0, b = 1;

        b /= a;
    }

    public static void bad_04()
    {
        long a = 0;
        int x = 10;

        long z = x / a;
    }
}