int factorial(int i)
{
    if (i <= 1)
    {
        return 1;
    }
    int ans;
    ans = factorial(i - 1);
    ans *= i;
    return ans;
}