vector<int> G[N];
bitset<N> vis;
void dfs(int s)
{
    vis[s] = 1;
    for (int t : G[s])
    {
        if (!vis[i])
            dfs(i);
    }
}