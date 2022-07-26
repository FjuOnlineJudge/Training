#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int bitcount(int x) { return x == 0 ? 0 : (x & 1) + bitcount(x >> 1); }
int main()
{
    string s;
    map<int, int> tb;
    int n, a[N];
    while (cin >> n)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            tb.clear();
            for (int j = 0; j < s.size(); j++)
                a[i] ^= (1 << int(s[j] - 'A'));
        }
        int n1 = n / 2, n2 = n - n1, x, ans = 0;
        for (int i = 0; i < (1 << n1); i++)
        {
            x = 0;
            for (int j = 0; j < n1; j++)
            {
                if (i & (1 << j))
                    x ^= a[j];
            }
            if (!tb.count(x) || bitcount(i) > bitcount(tb[x]))
                tb[x] = i;
        }
        for (int i = 0; i < (1 << n2); i++)
        {
            x = 0;
            for (int j = 0; j < n2; j++)
            {
                if (i & (1 << j))
                    x ^= a[n1 + j];
            }
            if (tb.count(x) && bitcount(i) + bitcount(tb[x]) > bitcount(ans))
                ans = (i << n1) ^ tb[x];
        }
        cout << bitcount(ans) << '\n';
        bool o = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans & (1 << i))
            {
                if (o)
                    cout << ' ';
                o = 1;
                cout << i + 1;
            }
        }
        cout << '\n';
    }
}
