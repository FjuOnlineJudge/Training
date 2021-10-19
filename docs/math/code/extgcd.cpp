// ax+by=c
int extgcd(int a, int b, int c, int &x, int &y)
{
    int d = a;
    if (b)
    {
        d = extgcd(b, a % b, c, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = c;
        y = 0;
    }
    return d;
}