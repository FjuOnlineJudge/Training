void dfs(int v, int p)
{
    tin[v] = ++timer;
    par[v][0] = p;
    if (v != p)
        dist[v] = dist[p] + 1;
    for (int it : G[v])
    {
        if (it != p)
            dfs(it, v);
    }
    tout[v] = ++timer;
}

int main()
{
    int q;
    cin >> n >> q;
    for (int i = 0, u, v; i < n - 1; ++i)
    {
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dist[1] = 1;
    dfs(1, 1);
    Doubling();
    for (int i = 0, u, v; i < q; ++i)
    {
        cin >> u >> v;
        int w = LCA(v, u);
        int res = (dist[u] + dist[v] - 2 * dist[w]) % 2;
        if (res)
            cout << "Road\n";
        else
            cout << "Town\n";
    }
}