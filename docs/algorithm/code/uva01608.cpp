#include <iostream>
#include <map>
using namespace std;
const int N = 200005;
int a[N], L[N], R[N];

bool sol(int a, int b)
{
    if (a >= b)
        return 1;
    for (int i = 0; i <= (b - a) / 2; i++)
    {
        if (L[a + i] < a && b < R[a + i])
        {
            return sol(a, a + i - 1) && sol(a + i + 1, b);
        }
        if (L[b - i] < a && b < R[b - i])
        {
            return sol(a, b - i - 1) && sol(b - i + 1, b);
        }
    }
    return 0;
}
int main()
{
    int t, n;
    map<int, int> tb;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        tb.clear();
        for (int i = 0; i < n; i++)
        {
            if (tb.find(a[i]) == tb.end())
            {
                L[i] = -1;
            }
            else
            {
                L[i] = tb[a[i]];
            }
            tb[a[i]] = i;
        }
        tb.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            if (tb.find(a[i]) == tb.end())
            {
                R[i] = n;
            }
            else
            {
                R[i] = tb[a[i]];
            }
            tb[a[i]] = i;
        }
        cout << (sol(0, n - 1) ? "non-boring\n" : "boring\n");
    }
}