vector<long long> v;

void dfs(set<long long> &s, int idx, int R, long long sum)
{
    if (idx >= R)
    {
        s.insert(sum);
        return;
    }
    dfs(s, idx + 1, R, sum);
    dfs(s, idx + 1, R, sum + v[idx]);
}

int main()
{
    IOS;
    int n;
    long long t, ans = 0;
    set<long long> s1, s2;
    cin >> n >> t;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        v.emplace_back(x);
    }
    dfs(s1, 0, n / 2, 0);
    dfs(s2, n / 2, n, 0);
    for (auto &x : s1)
    {
        auto it = s2.upper_bound(t - x);
        long long y = *(--it);
        if (x + y <= t)
            ans = max(ans, x + y);
    }
    cout << ans << '\n';
}