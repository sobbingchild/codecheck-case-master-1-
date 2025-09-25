#include <stdio.h>

void bad(int value)
{
    // bad
    switch (value)
    {
    case 1:
        printf("Case 1\n");
        break;
    case 2:
        printf("Case 2\n");
        break;
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
