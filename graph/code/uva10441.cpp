#include <bits/stdc++.h>
using namespace std;
const int ALP = 30;
const int MXN = 1005;
int n;
int din[ALP], dout[ALP];
int par[ALP];
vector<string> vs[MXN], ans;
bitset<MXN> vis, used[ALP];

void djsInit()
{
    for (int i = 0; i != ALP; ++i)
    {
        par[i] = i;
    }
}

int Find(int x) { return (x == par[x] ? (x) : (par[x] = Find(par[x]))); }

void init()
{
    djsInit();
    memset(din, 0, sizeof(din));
    memset(dout, 0, sizeof(dout));
    vis.reset();
    for (int i = 0; i != ALP; ++i)
    {
        vs[i].clear();
        used[i].reset();
    }
    return;
}

void dfs(int u)
{
    for (int i = 0; i != (int)vs[u].size(); ++i)
    {
        if (used[u][i])
        {
            continue;
        }
        used[u][i] = 1;
        string s = vs[u][i];
        int v = s[s.size() - 1] - 'a';
        dfs(v);
        ans.push_back(s);
    }
}

bool solve()
{
    int cnt = 1;
    for (int i = 0; i != n; ++i)
    {
        string s;
        cin >> s;
        int from = s[0] - 'a', to = s.back() - 'a';
        ++din[to];
        ++dout[from];
        vs[from].push_back(s);
        vis[from] = vis[to] = true;
        if ((from = Find(from)) != (to = Find(to)))
        {
            par[from] = to;
            ++cnt;
        }
    }
    if ((int)vis.count() != cnt)
    {
        return false;
    }
    int root, st, pin = 0, pout = 0;
    for (int i = ALP - 1; i >= 0; --i)
    {
        sort(vs[i].begin(), vs[i].end());
        if (vs[i].size())
            root = i;
        int d = dout[i] - din[i];
        if (d == 1)
        {
            ++pout;
            st = i;
        }
        else if (d == -1)
        {
            ++pin;
        }
        else if (d != 0)
        {
            return false;
        }
    }
    if (pin != pout || pin > 1)
    {
        return false;
    }
    ans.clear();
    dfs((pin ? st : root));
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        init();
        if (!solve())
        {
            cout << "***\n";
            continue;
        }
        for (int i = ans.size() - 1; i >= 0; --i)
        {
            cout << ans[i] << ".\n"[i == 0];
        }
    }
}