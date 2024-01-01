const int N = 1 << 11;
int n, m, cur;
long long int dp[2][N];

void update(int a, int b)
{
    if (b & (1 << m))// 如果上方沒放，就不可能放滿
        dp[cur][b ^ (1 << m)] += dp[1 - cur][a];
}

int main()
{
    while (cin >> n >> m)
    {
        if ((n * m) & 1) // NxM 是奇數就五姊
        {
            cout << "0\n";
            continue;
        }
        if (n == 1 || m == 1)
        {
            cout << "1\n";
            continue;
        }
        if (n < m)// 保證 m 比較小，降低 dp 陣列的大小
            swap(n, m);
        memset(dp, 0, sizeof(dp));
        cur = 0;
        dp[0][(1 << m) - 1] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cur ^= 1;
                memset(dp[cur], 0, sizeof(dp[cur]));
                for (int k = 0; k < (1 << m); k++)
                {
                    update(k, k << 1); // 不放
                    if (i && !(k & (1 << m - 1)))
                        update(k, (k << 1) ^ (1 << m) ^ 1); // 直放
                    if (j && !(k & 1))
                        update(k, (k << 1) ^ 3); // 橫放
                }
            }
        }
        cout << dp[cur][(1 << m) - 1] << '\n';
    }
}