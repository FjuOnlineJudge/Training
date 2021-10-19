int main()
{
    int n;
    cin >> n;
    vector<int> h(n + 5), dp(n + 5);
    FOR(i, 0, n) { cin >> h[i]; }
    fill(dp.begin(), dp.end(), INF);
    dp[0] = 0;
    FOR(i, 1, n) FOR(j, 1, 3)
    {
        if (i - j < 0)
        {
            break;
        }
        dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
    cout << dp[n - 1] << '\n';
}