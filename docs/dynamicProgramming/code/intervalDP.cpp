int dp[N][N];

// 遞迴
void f(int L, int R)
{
    if (L > R)
        return;
    if (dp[L][R] != 0)
        return;
    for (int i = L; i <= R; ++i)
    {
        f(L, i);
        f(i, R);
        dp[L][R] = ...;
    }
    return;
}

// 迴圈

for (int i = 1; i < N; ++i)
    for (int L = 0; L + i < N; ++L)
    {
        R = L + i;
        for (int k = L; k <= R; ++k)
        {
            dp[L][R] = ...;
        }
    }