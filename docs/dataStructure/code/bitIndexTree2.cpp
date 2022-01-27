int query(int i)
{
    int ans = 0;
    while (i)
    {
        ans += BIT[i];
        i -= lowbit(i);
    }
    return ans;
}