int A[100], S[100];

void generatePrefixSum(int n)
{
    for(int i = 1; i <= n; ++i)
        S[i] = S[i - 1] + A[i];
}

int getSum(int i, int j)
{
    return S[j] - S[i];
}