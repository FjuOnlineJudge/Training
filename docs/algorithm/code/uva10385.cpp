int n;
double L;
double vr[MXN], vk[MXN];

double f(double r)
{
    double t = r / vr[n - 1] + (L - r) / vk[n - 1];
    double ret = r / vr[0] + (L - r) / vk[0];
    for(int i = 1; i < n - 1; ++i) ret = min(ret, r / vr[i] + (L - r) / vk[i]);
    return ret - t;
}

double trinary_search(double L, double R) // find max
{
    for (int i = 0; i < 300; ++i)
    {
        double mL = (L + L + R) / 3, mR = (L + R + R) / 3;
        if (f(mL) > f(mR))
            R = mR;
        else
            L = mL;
    }
    return L;
}

int main()
{
    while (cin >> L >> n)
    {
        for(int i = 0; i < n; ++i) cin >> vr[i] >> vk[i];
        double ansL = trinary_search(0.0, L);
        double ansT = f(ansL);
        if (ansT < 0.00)
            printf("The cheater cannot win.\n");
        else
            printf("The cheater can win by %.0lf seconds with r = %.2lfkm and "
                   "k = %.2lfkm.\n",
                   ansT * 3600.0, ansL, L - ansL);
    }
}
