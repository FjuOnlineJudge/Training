int x;
// 使用 break
while (scanf("%d", &x))
{
    if (x == -1)
    {
        break;
    }
}
while (cin >> x)
{
    if (x == -1)
    {
        break;
    }
}

// 使用 C++ 的逗號運算子
while (scanf("%d", &x), x != -1)
{
}
while (cin >> x, x != -1)
{
}