int ans = A[1], mx = A[1];

for (int i = 2; i <= n; ++i)
{
    mx = max(mx, 0) + A[i];
    ans = max(ans, mx);
}