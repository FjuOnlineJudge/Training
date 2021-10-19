// 基本語法
if (條件_1)
{
    陳述_1;
}

// 複合陳述句
if (條件_1)
{
    陳述_1;
}
else if (條件_2)
{
    陳述_2;
}
... else if (條件_(n - 1)) { 陳述_(n - 1); }
else { 陳述n; }

// 巢狀 if
if (條件_1)
{
    if (條件_a)
    {
        陳述_a;
    }
}

// 範例，判斷 i 是否為奇數
scanf("%d", &i);
if (i % 2 == 0)
{
    printf("%d is odd\n", i);
}
else
{
    printf("%d is even\n", i);
}