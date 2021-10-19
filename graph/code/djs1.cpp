int Find(int x)
{
    if (x == p[x])
        return x;
    return find(p[x]);
}