# 標準輸入輸出
## 標準輸入輸出、文件輸入輸出
標準輸入：由鍵盤輸入。
標準輸出：輸出到螢幕。
文件輸入：由文件輸入。
文件輸出：輸出到文件。
標準/文件輸出輸入可以混用。
## C 標準輸入輸出, scanf 和 printf
scanf 和 printf 定義在標頭檔 `stdio.h`。
scanf 和 printf 會給定一個有格式的字串格式為：`\%[*][width][length]specifier`，在這個格式後面接參數，在格式字串有幾個參數，後面就要接相對應個數的參數。
```cpp
scanf("format string", var1, var2, ...);
printf("format string", varA, varB, ...);
```
specifier(格式碼)，是用來指定輸入的型態，下表為常用的格式碼：

| 格式碼 | 說明                   |
| ------ | ---------------------- |
| %d    | int                    |
| %u    | unsigned int           |
| %lld  | long long int          |
| %llu  | unsigned long long int |
| %f    | float                  |
| %lf   | double                 |

```cpp
#include <cstdio>

int main()
{
    int i;
    scanf("%d", &i);
    printf("%d\n", i);
    double d;
    scanf("%lf", &d);
    printf("%lf\n", d);
    char c;
    scanf(" %c", &c);
    printf("%c\n", c);
    scanf("%d %lf %c", &i, &d, &c);
    printf("%d %lf %c\n", i, d, c);
}
```

上面的例子會發現 scanf 的變數前面都會多一個 `&`，簡單來說就是 scanf 要的是記憶體位置，要更詳細理解要先學完指標。(編者認為這是當初設計沒想到的一個 bug)
width 在 printf 的用途為對右靠齊，如果輸出的字元數小於所設寬度，不足部分會用空白填滿；如果輸出的字元數大於所設寬度，則無效。
```cpp
#include <cstdio>

int main()
{
    int a = 25;
    printf("%2d\n", a);
    printf("%3d\n", a);
    printf("%4d\n", a);
    double b = 25.0;
    printf("%10f\n", b);
    printf("%11f\n", b);
    printf("%12f\n", b);
}
```
```
25
 25
  25
 25.000000
  25.000000
   25.000000
```
若無法事先知道寬度，可用 `*` 代替。
```cpp
#include <cstdio>

int main()
{
    int a = 25;
    printf("%*d\n", 2, a);
    printf("%*d\n", 3, a);
    printf("%*d\n", 4, a);
    double b = 25.0;
    printf("%*f\n", 10, b);
    printf("%*f\n", 11, b);
    printf("%*f\n", 12, b);
}
```
```
25
 25
  25
 25.000000
  25.000000
   25.000000
```
length 在 printf 的用途為指定輸出長度。整數部分，如果是輸出的字元數小於所設長度，不足部分會補 $0$；如果輸出的字元數大於所設長度，則無效。浮點數部分，所謂的輸出長度指的是小數點後的位數。
```cpp
#include <cstdio>

int main()
{
    int a = 25;
    printf("%.2d\n", a);
    printf("%.3d\n", a);
    printf("%.4d\n", a);
    double b = 25.0;
    printf("%.3f\n", b);
    printf("%.4f\n", b);
    printf("%.5f\n", b);
}
```
```
25
025
0025
25.000
25.0000
25.00000
```
若無法事先知道長度，亦可用 `*` 代替。

```cpp
#include <cstdio>

int main()
{
    int a = 25;
    printf("%.*d\n", 1, a);
    printf("%.*d\n", 2, a);
    printf("%.*d\n", 3, a);
    printf("%.*d\n", 4, a);
    double b = 25.0;
    printf("%.*f\n", 3, b);
    printf("%.*f\n", 4, b);
    printf("%.*f\n", 5, b);
}
```
```
25
25
025
0025
25.000
25.0000
25.00000
```
width 在 scanf 的用法，請參考 C 字串章節。
## C++ 輸入輸出, cin 和 cout
cin 和 cout 定義在標頭檔 `iostream`。
cin 和 cout 並不需要先給出格式，直接接你要輸出/輸入的變數名稱就好了。
```cpp
cin>>var1>>var2>>...;
cout<<var1<<var2<<var3<<<...;
```
```cpp
#include <iostream>
using namespace std;

int main()
{
    int i;
    cin >> i;
    cout << i << endl;
    double d;
    cin >> d;
    cout << d << endl;
    char c;
    cin >> c;
    cout << c << endl;
    cin >> i >> d >> c;
    cout << i << ' ' << d << ' ' << c << endl;
}
```

C++ 的 cout 也有設定寬度和長度的功能，需使用到標頭檔 `iomanip`。
寬度：setw，如果輸出的字元數小於所設寬度，不足部分會用空白填滿；如果輸出的字元數大於所設寬度，則無效
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 100;
    cout << setw(4) << a << '\n';
    cout << setw(5) << a << '\n';
    cout << setw(6) << a << '\n';
    double d = 1.414;
    cout << setw(4) << d << '\n';
    cout << setw(5) << d << '\n';
    cout << setw(6) << d << '\n';
}
```
```
 100
  100
   100
1.414
1.414
 1.414
```
長度：setprecision，只對浮點數有效。cout 有兩種表示方式，scientific 和 fixed，scientific 只會輸出有效位數，fixed 會將所有位數印出。
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 100;
    double d = 1.414;
    cout << setprecision(4) << a << '\n';
    cout << setprecision(5) << a << '\n';
    cout << setprecision(6) << a << '\n';

    cout << setprecision(4) << d << '\n';
    cout << setprecision(5) << d << '\n';
    cout << setprecision(6) << d << '\n';

    cout << fixed;
    cout << setprecision(4) << a << '\n';
    cout << setprecision(5) << a << '\n';
    cout << setprecision(6) << a << '\n';

    cout << setprecision(4) << d << '\n';
    cout << setprecision(5) << d << '\n';
    cout << setprecision(6) << d << '\n';

    cout << scientific;
    cout << setprecision(4) << a << '\n';
    cout << setprecision(5) << a << '\n';
    cout << setprecision(6) << a << '\n';

    cout << setprecision(4) << d << '\n';
    cout << setprecision(5) << d << '\n';
    cout << setprecision(6) << d << '\n';
}
```
```
100
100
100
1.414
1.414
1.414
100
100
100
1.4140
1.41400
1.414000
100
100
100
1.4140e+00
1.41400e+00
1.414000e+00
```
