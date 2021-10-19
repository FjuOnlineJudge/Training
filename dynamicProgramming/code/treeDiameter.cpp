#include <bits/stdc++.h>
using namespace std;
const int MXV = 15;
vector<int> G[MXV];
int high[MXV][2];
int ans[MXV], height[MXV];

void dfs(int u)
{
    height[u] = 1;
    for (int v : G[u])
    {
        dfs(v);
        height[u] = max(height[u], height[v] + 1);
        if (high[u][0] == 0 || height[high[u][0]] < height[v])
        {
            high[u][1] = high[u][0];
            high[u][0] = v;
        }
        else if (high[u][1] == 0 || height[high[u][1]] < height[v])
        {
            high[u][1] = v;
        }
    }
}

void dfs2(int u, int legnth)
{
    ans[u] = height[high[u][0]] + max(height[high[u][1]], legnth) + 1;
    for (int v : G[u])
    {
        if (v == high[u][0])
        {
            dfs2(v, max(height[high[u][1]], legnth) + 1);
        }
        else
        {
            dfs2(v, max(height[high[u][0]], legnth) + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        G[x].emplace_back(y);
    }
    dfs(1);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << '\n';
    }
}