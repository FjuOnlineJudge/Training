int low[MXV], depth[MXV];
bool is_cut_vertex[MXV], visit[MXV];
vector<int> G[MXV];

void dfs(int now, int cur_depth)
{
    visit[now] = true;
    depth[now] = low[now] = cur_depth;
    int cut_son = 0;
    for (auto i : G[now])
    {
        if (visit[i])
        { // ancestor
            low[now] = min(low[now], depth[i]);
        }
        else
        { // offspring
            dfs(i, cur_depth + 1);
            cut_son += 1;
            low[now] = min(low[now], low[i]);
            if (low[i] >= depth[now])
                is_cut_vertex[now] = true;
        }
    }
    if (cur_depth == 0)
        is_cut_vertex[now] = (cut_son != 1);
    return;
}