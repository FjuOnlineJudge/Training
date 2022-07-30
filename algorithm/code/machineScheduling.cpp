int main()
{
    int n, m;
    int a[10000];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n,greater<int>());
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    for (int i = 0; i < m && i < n; ++i)
    {
        ans = max(ans, a[i]);
        pq.push(a[i]);
    }
    for (int i = m; i < n; ++i)
    {
        int x = pq.top();
        pq.pop();
        x += a[i];
        ans = max(ans, x);
        pq.push(x);
    }
    cout << ans << '\n';
}
