#include <bits/stdc++.h>
using namespace std;
#define N 10010

int main()
{
    int t = 0, n, q;
    vector<int> a(N);
    while (cin >> n >> q, n)
    {
        cout << "CASE# " << ++t << ":\n";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.begin() + n);
        for (int j = 1, x; j <= q; j++)
        {
            cin >> x;
            auto it = lower_bound(a.begin(), a.begin() + n, x);
            if (it == a.begin() + n || *it != x)
                cout << x << " not found\n";
            else
                cout << x << " found at " << it - a.begin() + 1 << '\n';
        }
    }
}