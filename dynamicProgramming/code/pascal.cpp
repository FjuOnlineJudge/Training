int main()
{
    int dp[30][30];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 30; ++i)
    {
        dp[i][0] = dp[i][i] = 1;
    }
    for (int i = 1; i < 30; ++i)
    {
        for (int j = 1; j < 30; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}