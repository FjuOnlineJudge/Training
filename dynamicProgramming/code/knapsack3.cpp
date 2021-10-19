int dp[MXW + 1];
memset(dp, 0, sizeof(dp));
for (int i = 0; i < N; ++i)
{
    for (int j = MXW; j >= w[i]; --j)
    {
        dp[j] = max(dp[j − w[i]] + v[i], dp[j]);
    }
}