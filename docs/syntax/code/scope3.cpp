#include <iostream>
using namespace std;

void print_var()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << i << '\n';
    }
}

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        print_var();
    }
}

/*
0
1
2
0
1
2
0
1
2
*/