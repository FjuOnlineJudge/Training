vector<int> G[N];
bitset<N> vis;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int t : G[v])
        {
            if (!vis[t])
            {
                q.push(t);
                vis[t] = 1;
            }
        }
    }
}