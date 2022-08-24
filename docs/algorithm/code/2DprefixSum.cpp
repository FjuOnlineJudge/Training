int A[100][100], S[100][100];

void build()
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j];
}

int sum(int x1, int x2, int y1, int y2)
{
    return S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1 - 1][y1 - 1];
}