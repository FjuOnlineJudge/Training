int dp[2][MXW + 1];
memset(dp, 0, sizeof(dp));
for (int i = 0; i < N; ++i)
{
    for (int j = 0; j < w[i]; ++j)
    {
        dp[i & 1][j] = dp[(i & 1) ^ 1][j];
    }
    for (int j = w[i]; j <= MXW; ++j)
    {
        dp[i & 1][j] =
            max(dp[(i & 1) ^ 1][j - w[i]] + v[i], dp[(i & 1) ^ 1][j]);
    }
}