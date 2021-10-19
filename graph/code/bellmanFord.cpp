void bellman_ford(int s)
{
    d[s] = 0;
    p[s] = s;
    for (int i = 0; i < V - 1; i++)
    {
        for (int ss = 0; ss < V; ss++)
        {
            for (auto tt : v[ss])
            {
                if (d[ss] + w[ss][tt] < d[tt])
                {
                    d[tt] = d[ss] + w[ss][tt];
                    p[tt] = ss;
                }
            }
        }
    }
}
bool has_negative_cycle()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (d[i] + w[i][j] < d[j])
                return true;
        }
    }
    return false;
}