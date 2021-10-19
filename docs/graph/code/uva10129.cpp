#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 30;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
vector<int> din(MXV), dout(MXV);
vector<int> G[MXV];
bitset<MXV> vis;

void init()
{
    fill(din.begin(), din.end(), 0);
    fill(dout.begin(), dout.end(), 0);
    FOR(i, 0, MXV) G[i].clear();
    vis.reset();
}

void dfs(int u)
{
    vis[u] = true;
    for (int v : G[u])
        if (!vis[v])
            dfs(v);
}

bool ok(int st)
{
    int cnt1 = 0, cnt2 = 0;
    FOR(i, 0, MXV)
    {
        int d = dout[i] - din[i];
        if (d == 1)
        {
            ++cnt1;
            st = i;
        }
        else if (d == -1)
            ++cnt2;
        else if (d != 0)
            return false;
    }
    if (cnt1 != cnt2 || cnt1 > 1)
        return false;
    dfs(st);
    FOR(i, 0, MXV)
    {
        if ((din[i] || dout[i]) && !vis[i])
            return false;
    }
    return true;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        init();
        FOR(i, 0, n)
        {
            cin >> s;
            int u = s[0] - 'a', v = s.back() - 'a';
            ++dout[u];
            ++din[v];
            G[u].emplace_back(v);
        }
        if (ok(s[0] - 'a'))
            cout << "Ordering is possible.\n";
        else
            cout << "The door cannot be opened.\n";
    }
}