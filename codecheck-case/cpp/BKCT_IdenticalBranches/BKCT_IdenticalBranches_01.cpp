#include <cstdio>

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
        printf("Repeated code\n");
    }
    else
    {
        printf("Repeated code\n");
    }
}

void good_01(bool condition)
{
    // good
    if (condition)
    {
        printf("Repeated code\n");
    }
    else
    {
        printf("Another different branch\n");
    }
}
