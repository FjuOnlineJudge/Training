vector<long long> v(MXN);
int n, m;

bool f(long long x)
{
    int idx = 0;
    for (int i = 0; i < m; ++i)
    {
        long long cur = 0;
        while (idx < n && cur + v[idx] <= x)
        {
            cur += v[idx];
            ++idx;
        }
    }
    return idx == n;
}

int main()
{
    while (cin >> n >> m)
    {
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            sum += v[i];
        }
        long long L = 0, R = sum, ans = 0;
        while (L <= R)
        {
            int M = (L + R) >> 1;
            if (f(M))
            {
                R = M - 1;
                ans = M;
            }
            else
                L = M + 1;
        }
        cout << ans << '\n';
    }
}
