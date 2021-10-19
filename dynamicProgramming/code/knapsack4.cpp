int dp[MXW + 1];
memset(dp, 0, sizeof(dp));
for (int i = 0; i < N; ++i)
{
    for (int j = w[i]; j <= MXW; ++j)
    {
        dp[j] = max(dp[j − w[i]] + v[i], dp[j]);
    }
}