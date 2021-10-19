#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int a = 100;
    double d = 1.414;

    int x = 4; // 可更改並觀察結果

    // 整數範例
    cout << setw(x) << a << '\n';
    cout << setfill('x') << setw(x) << a << '\n';
    cout << setprecision(x) << a << '\n';
    cout << fixed << setprecision(x) << a << '\n';
    cout << scientific << setprecision(x) << a << '\n';
    cout << '\n';

    // 浮點數範例
    cout << setw(x) << d << '\n';
    cout << setfill('x') << setw(d) << a << '\n';
    cout << setprecision(x) << d << '\n';
    cout << fixed << setprecision(x) << d << '\n';
    cout << scientific << setprecision(x) << d << '\n';
}

/*
 100
x100
100
100
100

1.4140e+00
100
1.4140e+00
1.4140
1.4140e+00
*/