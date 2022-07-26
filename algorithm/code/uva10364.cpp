const int MXN = 30;
vector<int> v(MXN);
bitset<MXN> used;
int n,sum, avg;

bool dfs(int curSide, int curLength, int idx)
{
    // cout << curSide << ' ' << curLength << ' ' << idx << '\n';
    if(curLength == avg)
    {
        if(curSide == 3)
            return true;
        ++curSide;
        curLength = idx = 0;
    }
    for (int i = idx; i < n; ++i)
    {
        if(used[i] || curLength + v[i] > avg)
            continue;
        used[i] = true;
        if(dfs(curSide, curLength + v[i], i + 1))
            return true;
        used[i] = false;
    }
    return false;
}

void solve()
{
    sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.begin() + n, greater<int>());
    avg = sum / 4;
    used.reset();
    if (sum % 4 || v[0] > avg || !dfs(0, 0, 0))
        cout << "no\n";
    else
        cout << "yes\n";
}