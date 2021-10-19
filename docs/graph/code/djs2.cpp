int Find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}