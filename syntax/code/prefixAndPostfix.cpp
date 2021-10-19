#include <iostream>

int main()
{
    int n = 5, m = 5;
    printf("prefix:");
    while (--n)
    {
        printf(" %d", n);
    }
    printf("\n");

    printf("postfix:");
    while (m--)
    {
        printf(" %d", m);
    }
    printf("\n");
}

/*
prefix: 4 3 2 1
postfix: 4 3 2 1 0
*/