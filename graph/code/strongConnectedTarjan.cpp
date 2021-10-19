#include <bits/stdc++.h>
using namespace std;
const int MXV = 100005;
int sccCnt, sccNo[MXV];
vector<int> G[MXV], dep(MXV), low(MXV);
bitset<MXV> isStack, isRoot;
stack<int> st;
int t;

void init(int n, int m)
{
    t = 0;
    fill(dep.begin(), dep.end(), 0);
    sccCnt = 0;
    memset(sccNo, 0, sizeof(sccNo));
    isStack.reset();
    isRoot.set();
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = 1; i <= n; ++i)
    {
        G[i].clear();
    }
    for (int i = 0, x, y; i != m; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }
}

void tarjan(int u)
{
    dep[u] = low[u] = ++t;
    st.push(u);
    isStack[u] = true;
    for (auto v : G[u])
    {
        if (dep[v] == 0)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (isStack[v])
        {
            low[u] = min(low[u], dep[v]);
        }
    }
    if (low[u] == dep[u])
    {
        ++sccCnt;
        int tmp;
        do
        {
            tmp = st.top();
            st.pop();
            isStack[tmp] = false;
            sccNo[tmp] = sccCnt;
        } while (tmp != u);
    }
}

int main()
{
    init(n, m); // |V| = n, |E| = m
    for (int i = 1; i <= n; ++i)
    {
        if (dep[i] == 0)
        {
            tarjan(i);
        }
    }
}