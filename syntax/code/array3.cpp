int arr[10][10];             // 宣告
for (int i = 0; i < 10; ++i) // i 代表第一維的索引值
{
    for (int j = 0; j < 10; ++j) // j 代表第二維的索引值
    {
        arr[i][j] = i * 10 + j;
    }
}