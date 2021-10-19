void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}