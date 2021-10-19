vector<int> G[MXN];
vector<int> rev_G[MXN];
vector<int> leave;
bitset<MXN> visit;
int at_scc[MXN];

void dfs_for_stamp(int now)
{
    visit[now] = true;
    for (auto i : rev_G[now])
    {
        if (!visit[i])
        {
            dfs_for_stamp(i);
        }
    }
    leave.push_back(now);
}

void dfs_for_scc(int now, int cur_scc)
{
    visit[now] = true;
    at_scc[now] = cur_scc;
    for (auto i : G[now])
    {
        if (!visit[i])
        {
            dfs_for_scc(i, cur_scc);
        }
    }
}

int kosaraju(int n)
{
    visit.reset();
    leave.clear();
    for (int i = 0; i < n; ++i)
    {
        if (!visit[i])
        {
            dfs_for_stamp(i);
        }
    }
    visit.reset();
    int scc_count = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (!visit[leave[i]])
        {
            dfs_for_scc(leave[i], scc_count++);
        }
    }
    return scc_count;
}