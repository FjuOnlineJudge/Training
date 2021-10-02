# 最低共同祖先 (Lowest Common Ancestor, LCA)

在有根樹上任意兩點 $u,v$，兩點祖先交集中，深度最深的一個點，稱為兩點的最低共同祖先 (LCA)。利用 DFS 尋找兩點的 LCA 花 $O(V)$ 時間。如果一次要尋找多組點對的 LCA，這種辦法就容易超時。

另一種方法是倍增法，先用動態規劃建表：

- 狀態：$par[v][i]$ 代表 $v$ 的第 $2^i$ 層祖先。
- 初始狀態：$par[v][0]=u$, $u$ 為 $v$ 的父節點。
- 轉移：$par[v][i]=par[par[v][i-1]][i-1]$。

用 DFS 紀錄進入和離開的時間戳記，並且紀錄每個點的父節點 $par[v][0]$。再跑兩層迴圈求出轉移式的結果(倍增法)，建表就完成了。DFS 的時間複雜度為 $O(V+E)$，倍增法的時間複雜度為 $O(V\log V)$。

建表完成後，由於任意兩點 $u,v$ 的共同祖先有單調性，$u$ 點的所有祖先， 在 $LCA(u,v)$ (包含)之上的祖先是兩點的共同祖先，剩下的只是 $u$ 的祖先，因此可以用二分搜枚舉 $p$ 尋找 $LCA(u,v)$，在二分搜過程，時間戳記用於判斷 $p$ 是否為 $v$ 的祖先，一次查詢操作的時間複雜度為 $O(\log V)$。

```cpp
const int LOG = 20;
int par[N][LOG];
int tin[N], tout[N];
int timer = 0;

void dfs(int v, int p){
    tin[v] = ++timer;
    par[v][0] = p;
    for(int it: G[v]){
        if(it != p)dfs(it, v);
    }
    tout[v] = ++timer;
}

void Doubling(){
    for(int i = 1; i < N; ++i){
        for(int j = 1; j < LOG; ++j){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

bool anc(int v, int u){
    return tin[v] <= tin[u] && tout[u] <= tout[v]; 
}

int LCA(int v, int u){
    if(anc(v, u))return v;
    for(int j = LOG - 1; j >= 0; --j){
        if(!anc(par[v][j], u))v = par[v][j];
    }
    return par[v][0];
}
```

找出最低共同祖先的算法，可推廣到找尋 $(u,v)$ 路徑上的資訊，例如：

- 路徑長度
- 最小(大)權重的邊

## [UVa 11354 - Bond](https://onlinejudge.org/external/113/11354.pdf)

???+ Question "UVa 11354 - Bond"
    給定一張無向帶權圖，有多筆詢問，詢問 $(u,v)$ 之間的路徑最大權重邊權值最小為何。
    也就是詢問最小瓶頸樹中， $(u,v)$ 之間的路徑最大邊重權為何。

這題要先利用 Krusal 求出最小瓶頸樹，接著利用 LCA 求出每個點 $u$ 到它的第 $2^i$ 層祖先的路徑中的最大邊重權。

??? "參考程式碼"
    ```cpp
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

    int query(int x) { return (x == djs[x] ? x : djs[x] = query(djs[x])); }

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
        {
            for (int j = 1; j <= n; j++)
            {
                if (par[j][i - 1] == -1 || par[par[j][i - 1]][i - 1] == -1)
                    continue;
                par[j][i] = par[par[j][i - 1]][i - 1];
                maxcost[j][i] =
                    max(maxcost[j][i - 1], maxcost[par[j][i - 1]][i - 1]);
            }
        }
    }

    int solve(int p, int q)
    {
        if (depth[p] < depth[q])
            swap(p, q);
        int hibit, ans = -INF;
        for (hibit = 1; (1 << hibit) <= depth[p]; ++hibit)
            ;
        for (int i = hibit - 1; i >= 0; i--)
        {
            if (depth[p] - (1 << i) >= depth[q])
            {
                ans = max(ans, maxcost[p][i]);
                p = par[p][i];
            }
        }
        if (p == q)
        {
            return ans;
        }
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
        for (int ti = 0; cin >> n >> m; ++ti)
        {
            if (ti)
                cout << '\n';
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
    ```