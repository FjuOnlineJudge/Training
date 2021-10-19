int q[N], din[N];
vector<int> G[N];

bool topologicalSort(int n)
{
    int head = -1, tail = -1;
    for (int i = 0; i < n; ++i)
    {
        if (din[i] == 0)
        {
            q[++head] = 1;
        }
    }
    while (head > tail)
    {
        int s = q[++tail];
        for (int i : G[s])
        {
            if (--din[i] == 0)
                q[++head] = i;
        }
    }
    return head == n;
}