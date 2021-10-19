int p[N], rank[N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
        rnak[i] = 1;
    }
}
int Find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;
    if (rank[a] < rank[b])
        p[a] = b;
    else if (rank[a] > rank[b])
        p[b] = a;
    else
    {
        p[a] = b;
        rank[a]++;
    }
}