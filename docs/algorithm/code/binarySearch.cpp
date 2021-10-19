T binary_search()
{
    while (L < R)
    {
        int M = (L + R) >> 1;
        if (F(M))
            R = M;
        else
            L = M + 1;
    }
    return L;
}