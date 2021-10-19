int ans = A[1];
sum[1] = dp[1] = A[1];

for (int i = 2; i <= n; ++i)
{
    sum[i] = A[i] + sum[i - 1];
    dp[i] = min(dp[i - 1], sum[i]);
    ans = max(ans, sum[i] - dp[i - 1]);
}