int dp[30];
int f(int p, int n)
{
    cout << p << " call " << n << '\n';
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = f(n, n - 1) + f(n, n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    f(-1, 5);
}

/*
-1 call 5
5 call 4
4 call 3
3 call 2
2 call 1
2 call 0
3 call 1
4 call 2
5 call 3
*/