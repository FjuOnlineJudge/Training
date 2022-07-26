int n;
double a[MXN], b[MXN], c[MXN];

double f(double x)
{
    double ret = a[0] * x * x + b[0] * x + c[0];
    FOR(i, 1, n) ret = max(ret, a[i] * x * x + b[i] * x + c[i]);
    return ret;
}

double trinary_search(double L, double R)
{
    for (int i = 0; i < 300; ++i)
    {
        double mL = (L + L + R) / 3, mR = (L + R + R) / 3;
        if (f(mR) > f(mL))
            R = mR;
        else
            L = mL;
    }
    return L;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 0, n) cin >> a[i] >> b[i] >> c[i];
        cout << fixed << setprecision(4) << f(trinary_search(0.0, 1000.0)) << '\n';
    }
}
