struct Work{
    int t, d;
    bool operator<(const Work &rhs) const { return d < rhs.d; }
};

int main()
{
    int n = 0;
    Work a[10000];
    priority_queue<int> pq;
    while(cin >> a[n].t >> a[n].d)
        ++n;
    sort(a, a + n);
    int sumT = 0, ans = n;
    for (int i = 0; i < n; ++i)
    {
        pq.push(a[i].t);
        sumT += a[i].t;
        if(a[i].d<sumT)
        {
            int x = pq.top();
            pq.pop();
            sumT -= x;
            --ans;
        }   
    }
    cout << ans << '\n';
}