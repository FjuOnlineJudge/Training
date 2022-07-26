long long bill(long long x)
{
    if (x < 100)
        return 2 * x;
    if (x < 10000)
        return 3 * (x - 100) + 200;
    if (x < 1000000)
        return 5 * (x - 10000) + 29900;
    else
        return 7 * (x - 1000000) + 4979900;
}

int main()
{
    IOS;
    int a, b;
    while (cin >> a >> b, a || b)
    {
        long long tot = 0;
        long long L = 0, R = 1000000000;
        while (L <= R)
        {
            long long M = (L + R) >> 1;
            long long res = bill(M);
            if (res == a)
            {
                tot = M;
                break;
            }
            if (res < a)
                L = M + 1;
            else
                R = M - 1;
        }
        L = 0;
        R = tot;
        while (L <= R)
        {
            long long M = (L + R) >> 1;
            long long res = bill(tot - M) - bill(M);
            if (res == b)
            {
                cout << bill(M) << '\n';
                break;
            }
            if (res < b)
                R = M - 1;
            else
                L = M + 1;
        }
    }
}
