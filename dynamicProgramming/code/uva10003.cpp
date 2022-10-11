int c[N], dp[N][N];

int f(int L, int R)
{
    if (dp[L][R] != -1)
        return dp[L][R];
    if (L == R - 1)
        return dp[L][R] = 0;
    dp[L][R] = INT_MAX;
    for (int i = L + 1; i < R; ++i)
        dp[L][R] = min(dp[L][R], f(L, i) + f(i, R) + (c[R] - c[L]));
    return dp[L][R];
}