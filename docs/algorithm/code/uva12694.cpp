struct Line
{
    int L, R;
    bool operator<(const Line &rhs) const { return R < rhs.R; }
};

int main()
{
    int t;
    cin >> t;
    Line a[30];
    while (t--)
    {
        int n = 0;
        while (cin >> a[n].L >> a[n].R, a[n].L || a[n].R)
            ++n;
        sort(a, a + n);
        int ans = 1, R = a[0].R;
        for (int i = 1; i < n; i++)
        {
            if (a[i].L >= R)
            {
                ++ans;
                R = a[i].R;
            }
        }
        cout << ans << '\n';
    }
}