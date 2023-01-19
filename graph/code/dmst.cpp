struct Edge
{
    int u, v, cost;
};
// in,pre: 每個點最小權重入邊的權重和頂點
// id: 點的新編號, vis: 被誰訪問
vector<int> in(MXN), pre(MXN), id(MXN), vis(MXN);
vector<Edge> E;

int dmst(int root, int n, int m)
{
    int res = 0;
    while (1)
    {
        // 尋找非 root 的所有點權重最小的入邊
        fill(in.begin(), in.end(), INF);
        for (Edge &edge : E)
            if (edge.u != edge.v && edge.cost < in[edge.v])
            {
                in[edge.v] = edge.cost;
                pre[edge.v] = edge.u;
            }
        // 如果有一個點(除了 root)沒入邊，就無法形成樹形圖
        for (int i = 0; i < n; ++i)
            if (i != root && in[i] == INF)
                return -1;
        // 找環和縮點
        int num = 0;
        fill(id.begin(), id.end(), -1);
        fill(vis.begin(), vis.end(), -1);
        in[root] = 0;
        for (int i = 0; i < n; ++i)
        {
            res += in[i];
            int v = i;
            while (vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if (v != root && id[v] == -1)
            {
                for (int j = pre[v]; j != v; j = pre[j])
                    id[j] = num;
                id[v] = num++;
            }
        }
        // 沒有環代表已形成樹形圖
        if (num == 0)
            break;
        // 將沒有形成環的點和所有邊重新編號
        for (int i = 0; i < n; ++i)
            if (id[i] == -1)
                id[i] = num++;
        for (int i = 0; i < (int)E.size(); ++i)
        {
            Edge &edge = E[i];
            // 假設點 v 有兩條入邊 E1,E2，第一次選擇 E1，在縮點後 E2
            // 被選擇，所增加的 cost = E2 的權重 - E1
            // 的權重，為了避免重複計算權重，將邊重新編號時把所有未選入的邊權重扣除。
            if (id[edge.u] != id[edge.v])
                edge.cost -= in[edge.v];
            edge.u = id[edge.u];
            edge.v = id[edge.v];
        }
        n = num;
        root = id[root];
    }
    return res;
}