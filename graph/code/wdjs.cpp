int find(int u) // p[u]: 父節點, root: 根節點
{
    if (u != p[u])
        return p[u];
    int f = p[u];
    int root = find(p[u]);
    v[u] += v[p[u]];
    return p[u] = root;
}