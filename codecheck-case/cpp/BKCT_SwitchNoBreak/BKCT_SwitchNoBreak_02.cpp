#include <stdio.h>

void bad(int value)
{
    switch (value)
    {
    // bad
    case 1:
        printf("Case 1\n");
    // bad
    case 2:
        printf("Case 2\n");
    default:
        printf("Default case\n");
    }
}

void good(int value)
{
    switch (value)
    {
    // good
    case 1:
        printf("Case 1\n");
        break;
    // good
    case 2:
        printf("Case 2\n");
        break;
    default:
        printf("Default case\n");
    }
}
