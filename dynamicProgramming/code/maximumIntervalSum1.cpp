int ans = A[1];
sum[1] = A[1];

for (int i = 2; i <= n; ++i)
{
    sum[i] = A[i] + sum[i - 1];
}

for (int i = 2; i <= n; ++i)
{
    for (int j = i; j < n; ++j)
    {
        ans = max(sum[j] - sum[i - 1]);
    }
}