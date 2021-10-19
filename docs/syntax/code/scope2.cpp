#include <iostream>
using namespace std;
int i;

void print_var()
{
    for (i = 0; i < 3; ++i)
    {
        cout << i << '\n';
    }
}

int main()
{
    for (i = 0; i < 3; ++i)
    {
        print_var();
    }
}

/*
0
1
2
*/