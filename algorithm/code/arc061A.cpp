vector<int> v;
int sz;
long long ans;

void dfs(int idx, long long sum, long long cur)
{
    if (idx == sz)
    {
        ans += sum + cur;
        return;
    }
    dfs(idx + 1, sum, cur * 10 + v[idx]); // not to choose +
    dfs(idx + 1, sum + cur, v[idx]);      // choose +
}

int main()
{
    long long n;
    cin >> n;
    while (n)
    {
        v.emplace_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    sz = (int)v.size();
    ans = 0;
    dfs(0, 0, 0);
    cout << ans / 2 << '\n';
}
