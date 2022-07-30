struct Work
{
    int t, d;
    bool operator<(const Work &rhs) const { return d < rhs.d; }
};

int main()
{
    int n;
    Work a[10000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].t >> a[i].d;
    sort(a, a + n);
    int maxL = 0, sumT = 0;
    for (int i = 0; i < n; ++i)
    {
        sumT += a[i].t;
        maxL = max(maxL, sumT - a[i].d);
    }
    cout << maxL << '\n';
}