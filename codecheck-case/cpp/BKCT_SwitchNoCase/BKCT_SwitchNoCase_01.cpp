#include <stdio.h>

void bad(int value)
{
    // bad
    switch (value)
    {
    default:
        printf("Default case\n");
    }
}

void good(int value)
{
    // good
    switch (value)
    {
    case 1:
        printf("Case 1\n");
        break;
    case 2:
        printf("Case 2\n");
        break;
    default:
        printf("Default case\n");
    }
}
