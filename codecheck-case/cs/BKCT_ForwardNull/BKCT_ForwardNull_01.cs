using System;

public class BKCT_ForwardNull_01
{
    public void BadMethod1()
    {
        string str = null;
        if (str == null)
        {
            // bad
            Console.WriteLine(str.Length); // 在为空的分支中使用
        }
    }

    public void BadMethod2()
    {
        string str = null;
        if (str != null)
        {
            return;
        }
        // bad
        Console.WriteLine(str.Length); // 在为空的分支中使用
    }

    public void BadMethod3(string str)
    {
        if (str != null)
        {
            str = null;
        }
        // bad
        Console.WriteLine(str.Length); // 在不再次检查是否为空的情况下使用
    }

    public void BadMethod4(string str)
    {
        if (str == null)
        {
            // do nothing
        }
        // bad
        Console.WriteLine(str.Length); // 在不再次检查是否为空的情况下使用
    }

    public void GoodMethod1()
    {
        string str = null;
        if (str != null)
        {
            // good
            Console.WriteLine(str.Length);
        }
    }

    public void GoodMethod2()
    {
        string str = null;
        if (str == null)
        {
            return;
        }
        // good
        Console.WriteLine(str.Length);
    }

    public void GoodMethod3(string str)
    {
        if (str == null)
        {
            str = "aaa";
        }
        // good
        Console.WriteLine(str.Length);
    }

    public void GoodMethod4(string str)
    {
        if (str == null)
        {
            return;
        }
        // good
        Console.WriteLine(str.Length);
    }
}