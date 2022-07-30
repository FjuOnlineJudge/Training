struct Work
{
    int d, p;
    bool operator<(const Work &rhs) const { return p > rhs.p; }
};

int main()
{
    int n;
    Work a[100005];
    bitset<100005> ok;
    while (cin >> n)
    {
        ok.reset();
        for (int i = 0; i < n; ++i)
            cin >> a[i].d >> a[i].p;
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = a[i].d;
            while (j--)
                if (!ok[j])
                {
                    ans += a[i].p;
                    ok[j] = true;
                    break;
                }
        }
        cout << ans << '\n';
    }
}