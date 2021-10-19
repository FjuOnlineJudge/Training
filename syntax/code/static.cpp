#include <iostream>
using namespace std;

void addSum(int i)
{
    static int sum = 0;
    sum += i;
    cout << "The current sum is: " << sum << '\n';
}

int main()
{
    for (int i = 1; i <= 5; ++i)
    {
        addSum(i);
    }
}

/*
The current sum is: 1
The current sum is: 3
The current sum is: 6
The current sum is: 10
The current sum is: 15
*/