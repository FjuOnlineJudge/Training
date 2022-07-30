struct Line
{
    double L, R;
    bool operator<(const Line &rhs) const { return R < rhs.R; }
};

int main()
{
    double L, d;
    int n;
    Line a[100005];
    while (cin >> L)
    {
        cin >> d >> n;
        for (int i = 0; i < n; ++i)
        {
            double x, y;
            cin >> x >> y;
            double r = sqrt(d * d - y * y);
            a[i].L = max(0.0, x - r);
            a[i].R = min(L, x + r);
        }
        sort(a, a + n);
        int ans = 1, R = a[0].R;
        for (int i = 1; i < n; ++i)
        {
            if(a[i].L > R)
            {
                R = a[i].R;
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}
