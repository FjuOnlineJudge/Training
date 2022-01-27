void update(int i)
{
    while (i < N)
    {
        ++BIT[i];
        i += lowbit(i);
    }
}