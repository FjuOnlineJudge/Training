int Phi(int n)
{
    int ret = n;
    for (int i : p)
    {
        if (i * i > n)
            break;
        if (n % i == 0)
        {
            ret /= i;
            ret *= i - 1;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
    {
        ret /= n;
        ret *= n - 1;
    }
    return ret;
}