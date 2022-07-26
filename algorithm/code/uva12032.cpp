int n;
vector<int> v(MXN);

bool f(int k)
{
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] - v[i - 1] > k)
            return false;
        if (v[i] - v[i - 1] == k)
            --k;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    v[0] = 0;
    for (int ti = 1; ti <= t; ++ti)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> v[i];
        int L = 1, R = v[n], ans = 0;
        while (L <= R)
        {
            int M = (L + R) >> 1;
            if (f(M))
            {
                ans = M;
                R = M - 1;
            }
            else
                L = M + 1;
        }
        cout << "Case " << ti << ": " << ans << '\n';
    }
}
