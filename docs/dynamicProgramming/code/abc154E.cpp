#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
int dp[105][4][2];

int main()
{
    string s;
    int n, K;
    cin >> s >> K;
    n = (int)s.size();
    dp[0][0][0] = 1;
    FOR(i, 0, n) FOR(j, 0, 4) FOR(k, 0, 2)
    {
        int nd = (s[i] - '0');
        FOR(d, 0, 10)
        {
            int ni = i + 1, nj = j, nk = k;
            if (d != 0)
                ++nj;
            if (nj > K)
                continue;
            if(k == 0)
            {
                if(d > nd)
                    continue;
                if(d < nd)
                    nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << '\n';
}