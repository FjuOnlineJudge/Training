void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;
    p[a] = b;
}