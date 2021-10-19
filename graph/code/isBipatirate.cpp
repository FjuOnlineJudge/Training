#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int color[N];
vector<int> v[N];

bool dfs(int s)
{
    for (auto it : v[s])
    {
        if (color[it] == -1)
        {
            color[it] = 3 - color[s];
            if (!dfs(it))
                return false;
        }
        if (color[s] == color[it])
            return false;
    }
    return true;
}

void isBipatirate()
{
    bool ok = true;
    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            ok &= dfs(i);
        }
    }
    if (ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}