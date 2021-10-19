int dp[30];
int f(int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = f(n - 1) + f(n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    cout << f(25) << '\n';
}