int ans = A[1], dp[N];

for (int i = 2; i <= n; ++i)
{
    dp[i] = max(dp[i - 1], 0) + A[i];
    ans = max(ans, dp[i]);
}