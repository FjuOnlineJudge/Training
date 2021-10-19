LL P = 1, ans = 0;
for (int i = 0; i < n; ++i)
    P *= m[i];
for (int i = 0; i < n; ++i)
{
    LL a = P / m[i], x, y;
    extgcd(a, m[i], x, y);
    ans = (ans + r[i] * a * x) % P;
}
cout << (ans + P) % P << '\n';