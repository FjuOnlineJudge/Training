vector<int> p;
bitset<MAXN> is_notp;
void PrimeTable(int n)
{
    is_notp.reset();
    is_notp[0] = is_notp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_notp[i])
            continue;
        p.push_back(i);
        for (int j = i * i; j <= n; j += i)
        {
            is_notp[j] = 1;
        }
    }
}