for (int i = 0; i < N; ++i)
    cin >> sp[0][i];
for (int i = 1; i < LOG; ++i)
{
    for (int j = 0; j + p2[i] - 1 < n; ++j)
    {
        sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + p2[i - 1]]);
    }
}