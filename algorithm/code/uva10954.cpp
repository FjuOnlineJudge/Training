int main()
{

    int n, x;
    while (cin >> n, n)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        while (n--)
        {
            cin >> x;
            q.push(x);
        }
        long long ans = 0;
        while (q.size() > 1)
        {
            x = q.top();
            q.pop();
            x += q.top();
            q.pop();
            q.push(x);
            ans += x;
        }
        cout << ans << endl;
    }
}