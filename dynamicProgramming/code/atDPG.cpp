int ans = 0;
int din[MXV]; // din[v]: indegree of v
deque<int> q;
for(int i = 0; i <= n; ++i) if (din[i] == 0) { q.push_back(i); }
while (!q.empty())
{
    int u = q.front();
    q.pop_front();
    ans = max(ans, dp[u]);
    for (int v : G[u])
    {
        if (dp[v] < dp[u] + 1)
            dp[v] = dp[u] + 1;
        --din[v];
        if (din[v] == 0)
            q.push_back(v);
    }
}