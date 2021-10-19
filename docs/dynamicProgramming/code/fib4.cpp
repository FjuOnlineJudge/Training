int main()
{
    int dp[30];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 30; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[5] << '\n';
}