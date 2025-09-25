#include <cstdio>


void bad_01()
{
    return;
    // bad
    printf("This code is unreachable\n");
}


void bad_02()
{
    if (true)
    {
        return;
        // bad
        int x = 10; // Unreachable
    }
}

void bad_03()
{
    for (int i = 0; i < 10; i++)
    {
        if (i > 5)
        {
            break;
            // bad
            int a = 1;
        }
    }
}

void bad_04()
{
    int i = 5;
    while (i--)
    {
        if (i < 2)
        {
            break;
            // bad
            int a = 1;
        }
    }
}
