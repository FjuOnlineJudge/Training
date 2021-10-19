// 0~100 中的奇數和
int sum = 0;
for (int i = 0; i <= 100; i += 1)
{
    if (i % 2 != 0)
    {
        sum += i;
    }
}