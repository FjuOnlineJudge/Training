#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

bool isPrime(int n)
{
    FOR(i, 2, n)
    {
        if (i * i > n)
            return true;
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    if (isPrime(n))
        cout << "1\n";
    else if (n % 2 == 0 || isPrime(n - 2))
        cout << "2\n";
    else
        cout << "3\n";
}
