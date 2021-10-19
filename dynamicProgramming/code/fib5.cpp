int main()
{
    int dp[30];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 0; i < 30; ++i)
    {
        if (i + 1 < 30)
        {
            dp[i + 1] += dp[i];
        }
        if (i + 2 < 30)
        {
            dp[i + 2] += dp[i];
        }
    }
    cout << dp[5] << '\n';
}