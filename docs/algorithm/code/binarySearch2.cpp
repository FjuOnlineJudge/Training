// 情況 1
T binary_search()
{
    int ok = 1, ng = n;
    while(abs(ok - ng) > 1)
    {
        int M = (ok + ng) >> 1;
        if(f(M))ok = M;
        else ng = M;
    }
}

// 情況 2
T binary_search()
{
    int ok = n, ng = 1;
    while(abs(ok - ng) > 1)
    {
        int M = (ok + ng) >> 1;
        if(f(M))ok = M;
        else ng = M;
    }
}