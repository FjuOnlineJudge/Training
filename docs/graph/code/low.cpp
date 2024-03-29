int low[MXV], depth[MXV];
bool visit[MXV];
vector<int> G[MXV];

void dfs(int now, int cur_depth)
{
    visit[now] = true;
    depth[now] = low[now] = cur_depth;
    for (auto i : G[now])
    {
        if (visit[i])
        { // ancestor
            low[now] = min(low[now], depth[i]);
        }
        else
        { // offspring
            dfs(i, cur_depth + 1);
            low[now] = min(low[now], low[i]);
        }
    }
    return;
}