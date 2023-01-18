#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
const int INF = 1e9;
const int LOG = 25;

struct Edge
{
    int s, t, w;
    Edge(){};
    Edge(int _s, int _t, int _w) : s(_s), t(_t), w(_w) {}
    bool operator<(const Edge &rhs) const { return w < rhs.w; }
};
int n, m, djs[N], depth[N], par[N][LOG], maxcost[N][LOG];
vector<Edge> edges;
vector<int> G[N];

void init()
{
    memset(par, -1, sizeof(par));
    memset(maxcost, -1, sizeof(maxcost));
    edges.clear();
    for (int i = 0; i < N; i++)
    {
        djs[i] = i;
        G[i].clear();
    }
}

int query(int x) { return (x == djs[x] ? x : djs[x] = query(djs[x])); }

void MST()
{
    for (int i = 0; i < m; i++)
    {
        int fa = query(edges[i].s), fb = query(edges[i].t);
        if (fa != fb)
        {
            djs[fa] = fb;
            G[edges[i].s].push_back(i);
            G[edges[i].t].push_back(i);
        }
    }
}

void dfs(int s, int f)
{
    depth[s] = depth[f] + 1;
    par[s][0] = f;
    for (auto i : G[s])
    {
        // 不知道 s 存在這條邊的哪個位置，用 xor 消除同樣的數字，留下來的就是另外一個點
        int t = edges[i].s ^ edges[i].t ^ s; 
        if (t != f)
        {
            maxcost[t][0] = edges[i].w;
            dfs(t, s);
        }
    }
}

void preprocess()
{
    for (int i = 1; i <= LOG; i++)
        for (int j = 1; j <= n; j++)
        {
            if (par[j][i - 1] == -1 || par[par[j][i - 1]][i - 1] == -1)
                continue;
            par[j][i] = par[par[j][i - 1]][i - 1];
            maxcost[j][i] =
                max(maxcost[j][i - 1], maxcost[par[j][i - 1]][i - 1]);
        }
}

int solve(int p, int q)
{
    if (depth[p] < depth[q])
        swap(p, q);
    int hibit, ans = -INF;
    for (hibit = 1; (1 << hibit) <= depth[p]; ++hibit)// p 的深度以二進位表示的最高位
        ;
    // 把 p,q 兩個點的深度調整到一樣
    for (int i = hibit - 1; i >= 0; i--)
        if (depth[p] - (1 << i) >= depth[q])
        {
            ans = max(ans, maxcost[p][i]);
            p = par[p][i];
        }
    if (p == q)
        return ans;
    // 讓 p,q 變成最低共同祖先的兒子
    for (int i = hibit - 1; i >= 0; i--)
    {
        if (par[p][i] == -1 || par[p][i] == par[q][i])
            continue;
        ans = max({ans, maxcost[p][i], maxcost[q][i]});
        p = par[p][i];
        q = par[q][i];
    }
    return max({ans, maxcost[p][0], maxcost[q][0]});
}

int main()
{
    cin.tie(NULL);
    for (int ti = 0; cin >> n >> m; ++ti)
    {
        if (ti) cout << '\n';
        init();
        for (int i = 0; i < m; i++)
        {
            int s, t, w;
            cin >> s >> t >> w;
            edges.emplace_back(s, t, w);
        }
        sort(edges.begin(), edges.end());
        MST();
        dfs(1, -1);
        preprocess();
        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            cout << solve(x, y) << '\n';
        }
    }
}