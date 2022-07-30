struct Line
{
    int L, R;
    bool operator<(const Line &rhs) const
    {
        if (L != rhs.L)
            return L < rhs.L;
        return R < rhs.R;
    }
};

int main()
{
    int n;
    Line a[10005];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i].L >> a[i].R;
        sort(a, a + n);
        int ans = 0, L = a[0].L, R = a[0].R;
        for (int i = 1; i < n; i++)
        {
            if (a[i].L < R)
                R = max(R, a[i].R);
            else
            {
                ans += R - L;
                L = a[i].L;
                R = a[i].R;
            }
        }
        cout << ans + (R - L) << '\n';
    }
}
