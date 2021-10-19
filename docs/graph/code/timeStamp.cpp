int tin[N], tout[N];
int timer = 0;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    for (int it : G[v])
    {
        if (it != p)
            dfs(it, v);
    }
    tout[v] = ++timer;
}