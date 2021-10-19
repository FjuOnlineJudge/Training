typedef pair<int, int> PII;
int low[MXV], depth[MXV];
bool is_cut_vertex[MXV], visit[MXV];
vector<int> G[MXV];
vector<PII> BCC[MXV];
int bcc_cnt = 0;
stack<PII> st;

void dfs(int now, int cur_depth, int f)
{
    visit[now] = true;
    depth[now] = low[now] = cur_depth;
    int cut_son = 0;
    for (auto i : G[now])
    {
        if (i == f)
            continue;
        if (visit[i])
        { // ancestor
            if (depth[i] < depth[now])
            {
                low[now] = min(low[now], depth[i]);
                st.push({now, i});
            }
        }
        else
        { // offspring
            st.push({now, i});
            dfs(i, cur_depth + 1, now);
            cut_son += 1;
            low[now] = min(low[now], low[i]);
            if (low[i] >= depth[now])
            {
                is_cut_vertex[now] = true;
                auto t = st.top();
                st.pop();
                while (t != make_pair(now, i))
                {
                    BCC[bcc_cnt].push_back(t);
                    t = st.top();
                    st.pop();
                }
                BCC[bcc_cnt].push_back(t);
                ++bcc_cnt;
            }
        }
    }
    if (cur_depth == 0)
        is_cut_vertex[now] = (cut_son != 1);
    return;
}