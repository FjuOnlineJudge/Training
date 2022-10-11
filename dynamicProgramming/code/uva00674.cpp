int coin[6] = {0, 1, 5, 10, 25, 50};
unsigned long long int poss[6][7500];

int main()
{
    poss[0][0] = 1;
    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < coin[i]; j++)
            poss[i][j] = poss[i - 1][j];
        for (int j = coin[i]; j < 7500; j++)
            poss[i][j] = poss[i - 1][j] + poss[i][j - coin[i]];
    }
    int a;
    while (cin >> a)
        cout << poss[5][a] << endl;
}