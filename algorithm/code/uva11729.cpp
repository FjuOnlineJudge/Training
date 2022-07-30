struct Data
{
    int b, j;
    bool operator<(const Data &rhs) const { return j > rhs.j; }
};

int main()
{
    int n, ti = 0;
    Data a[1005];
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> a[i].b >> a[i].j;
        sort(a, a + n);
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += a[i].b;
            ans = max(ans, sum + a[i].j);
        }
        cout << "Case " << ++ti << ": " << ans << '\n';
    }
}
