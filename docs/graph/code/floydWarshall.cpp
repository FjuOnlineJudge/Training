for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            w[i][j] = w[j][i] = min(w[i][j], max(w[i][k], w[k][j]));