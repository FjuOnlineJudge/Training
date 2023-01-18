// 情況 1
T binary_search()
{
    int L = 1, R = n;
    while(L < R - 1) // 避免無限迴圈
    {
        int M = (L + R) >> 1;
        if(f(M))L = M;
        else R = M - 1;
    }
    if(L == r - 1 && f(R)) ++L;
    if(!f(L))return -1;
    return L;
}

// 情況 2
T binary_search()
{
    int L = 1, R = n;
    while(L < R)
    {
        int M = (L + R) >> 1;
        if(f(M))R = M;
        else L = M + 1;
    }
    if(L == n && !f(L))return -1;
    return L;
}