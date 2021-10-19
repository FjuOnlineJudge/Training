struct edge
{
    int s, t;
    LL d;
    edge(){};
    edge(int s, int t, LL d) : s(s), t(t), d(d) {}
};

struct heap
{
    LL d;
    int p; // point
    heap(){};
    heap(LL d, int p) : d(d), p(p) {}
    bool operator<(const heap &b) const { return d > b.d; }
};

int d[N], p[N];
vector<edge> edges;
vector<int> G[N];
bitset<N> vis;

void dijkstra(int ss)
{
    priority_queue<heap> Q;
    for (int i = 0; i < V; i++)
        d[i] = INF;
    d[ss] = 0;
    p[ss] = -1;
    vis.reset() : Q.push(heap(0, ss));
    heap x;
    while (!Q.empty())
    {
        x = Q.top();
        Q.pop();
        int p = x.p;
        if (vis[p])
            continue;
        vis[p] = 1;
        for (int i = 0; i < G[p].size(); i++)
        {
            edge &e = edges[G[p][i]];
            if (d[e.t] > d[p] + e.d)
            {
                d[e.t] = d[p] + e.d;
                p[e.t] = G[p][i];
                Q.push(heap(d[e.t], e.t));
            }
        }
    }
}