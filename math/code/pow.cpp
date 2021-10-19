T pow(int a, int b, int c)
{ // calculate a^b%c
    T res = 1, tmp = a;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * tmp % c;
        tmp = tmp * tmp % c;
    }
    return res;
}