#include <bits/stdc++.h>
using namespace std;
const int MXV = 200000 + 5;

int p[MXV], sum[MXV], sz[MXV];
int tot = -1, id[MXV];
struct DisjointSet
{
    void init(int n = MXV - 1)
    {
        for (int i = 0; i <= n; i++)
        {
            sz[i] = 1;
            p[i] = i;
            sum[i] = i;
            id[i] = i;
        }
        tot = n;
    }
    int find(int u) { return u == p[u] ? u : find(p[u]); }
    void Union(int x, int y)
    {
        int fx = find(id[x]), fy = find(id[y]);
        if (fx == fy)
            return;
        sz[fy] += sz[fx];
        sum[fy] += sum[fx];
        p[fx] = fy;
    }
};

int main()
{
    int n, m;
    DisjointSet djs;
    while (cin >> n >> m)
    {
        int x, y, z;
        djs.init(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> x;
            if (x == 3)
            {
                cin >> y;
                int fy = djs.find(id[y]);
                cout << sz[fy] << ' ' << sum[fy] << '\n';
                continue;
            }
            cin >> y >> z;
            int fy = djs.find(id[y]), fz = djs.find(id[z]);
            if (fy == fz)
                continue;
            if (x == 2)
            {
                // remove from old set
                sz[fy] -= 1;
                sum[fy] -= y;
                // create new set
                id[y] = ++tot;
                p[id[y]] = id[y];
                sz[id[y]] = 1;
                sum[id[y]] = y;
            }
            djs.Union(y, z);
        }
    }
}
