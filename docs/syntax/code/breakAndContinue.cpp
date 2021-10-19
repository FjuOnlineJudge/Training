#include <iostream>

int main()
{
    printf("break:");
    for (int i = 0; i < 5; ++i)
    {
        if (i == 2)
        {
            break;
        }
        printf(" %d", i);
    }
    printf("\n");

    printf("continue:");
    for (int i = 0; i < 5; ++i)
    {
        if (i == 2)
        {
            continue;
        }
        printf(" %d", i);
    }
    printf("\n");
}

/*
break: 0 1
continue: 0 1 3 4
*/