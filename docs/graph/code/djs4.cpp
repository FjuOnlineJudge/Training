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