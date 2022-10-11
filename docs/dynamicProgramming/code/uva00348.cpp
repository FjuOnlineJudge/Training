int f(int L, int R)
{
    if (L == R)
        return dp[L][R] = 0;
    if (dp[L][R] != -1)
        return dp[L][R];
    dp[L][R] = INT_MAX;
    for (int i = L; i < R; ++i)
    {
        int res = f(L, i) + f(i + 1, R) + x[L] * x[i + 1] * x[R + 1];
        if(res < dp[L][R])
        {
            dp[L][R] = res;
            to[L][R] = i;
        }
    }
    return dp[L][R];
}

void dfs(int L, int R)
{
    if(L==R)
    {
        cout << "A" << L + 1;
        return;
    }
    if(L==R-1)
    {
        cout << "(A" << L + 1 << " x A" << R + 1 << ")";
        return;
    }
    cout << "(";
    dfs(L, to[L][R]);
    cout << " x ";
    dfs(to[L][R] + 1,R);
    cout << ")";
}