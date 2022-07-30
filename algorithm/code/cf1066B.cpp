
int main()
{
    int n, r;
    int a[1005];
    cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int i = 1, ans = 0;
    while (i <= n)
    {
        int R = min(i + r - 1, n), L = max(i - r + 1, 0), nextR = -1;
        for (int j = R; j >= L; --j)
        {
            if (a[j])
            {
                nextR = j;
                break;
            }
        }
        if (nextR == -1)
        {
            ans = -1;
            break;
        }
        ++ans;
        i = nextR + r;
    }
    cout << ans << '\n';
}
