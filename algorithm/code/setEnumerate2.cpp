const int N = 20; // max element size

for (int i = 1; i < (1 << n); ++i)
{
    bitset<N> b(i);
    for (int j = 0; j < n; ++j)if(b[j])
    {
        ...
    }
}