void swap(int x, int y)
{
    cout << x << ' ' << y << '\n'; // 1 2
    int t = x;
    x = y;
    y = t;
    cout << x << ' ' << y << '\n'; // 2 1
}

int main()
{
    int a = 1, b = 2;
    cout << a << ' ' << b << '\n'; // 1 2
    swap(a, b);
    cout << a << ' ' << b << '\n'; // 1 2
}