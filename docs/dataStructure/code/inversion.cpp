#define lowbit(x) ((x) & (-x))
void update(int x)
{
    while (x < MXN)
    {
        ++BIT[x];
        x += lowbit(x);
    }
}

int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += BIT[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
    while (cin >> n)
    {
        int ans = 0, x;
        memset(BIT, 0, sizeof(BIT));
        for(int i = 1; i <= n; ++i)
        {
            cin >> x;
            ++x;
            update(x);
            ans += i - query(x);
        }
    }
}