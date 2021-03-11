# 函式與遞迴

## 函式

如果程式裡有一段會重複出現的程式碼，可以將這段程式碼寫成一個函式，這樣可以減少程式的長度，及降低維護的難度，以下為其語法：

```cpp
return_type function_name(parameter list) {
  \\ Do something... 
  return data;
}
```

- `function_name`: 函式的名稱
- `parameter`: 函式的參數
- `return_type`: 函式的回傳值型態，可為 `C/C++` 提供的[基礎資料型態](./type.md)或是[自定義的結構](./structure.md)，如果不需有回傳值，可設為 `void`，
- `return` 是 `C/C++` 關鍵子，回傳函式結果，需與函式的回傳值型態相符。當函式的回傳值型態為 `void`，可以省略。

=== "範例 1"

    ```cpp
    int sum(int x, int y) {
      int sum = 0;
      sum += x;
      sum += y;
      return x + y;
    }
    ```

=== "範例 2"

    ```cpp
    void print_hello() {
      cout << "Hello\n";
      return; // 可省略
    }
    ```

`main` 是 `C/C++` 程式的入口函式，接受命令列的參數，正常情況會回傳 $0$ 代表正常運作。

## 變數範圍 (Scope) 和生命週期 (Lifttime)
在 `C++` 中，一個變數可被使用的區域，稱為範圍 (Scope)，每種變數都有自己的生命週期 (Lifttime)，範圍可分為很多種，這裡我們只談三種，包含全域變數 (Global variable)、區域變數 (Local variable) 與區塊變數 (Block variable)。

- 全域變數：全域變數是指定義在函式外部的變數，整個程式都可以使用，全域變數通常為常數，或是多個函式共用的變數。全域變數的生命週期始於程式開始，終於程式結束。
- 區域變數：區域變數是指定義在函式內部的變數，只限該函式使用，區域變數的生命週期始於函式開始，終於函式結束。
- 區塊變數：區域變數是指定義在區塊內部的變數，只限該區塊使用，區塊包含 `if`、`while`、`for` 區塊，區塊變數的生命週期始於區塊開始，終於區塊結束。

```cpp
#include <iostream>
using namespace std;
const int N = 100; // 全域變數
int var1 = 1; // 全域變數

void print_var1() { cout << var1 << '\n'; }

int main()
{
    int var2 = N; // 區域變數
    for (int i = 0; i < var2; ++i) // 區塊變數
    {
        ++var1;
        print_var1();
    }
}
```

???+ warning "注意"
    將所有變數都設為全域變數固然方便，但會產生名稱空間重疊的問題(下面兩個範例程式，因為變數定義位置不同，造成不同結果)，造成維護上的困難，應小心使用，能擺放到函式內的變數，不應該設為全域變數，能擺放到區塊內的變數，不應該設為區域變數。

    === "範例 1(名稱空間重疊)"

        ```cpp
        #include <iostream>
        using namespace std;
        int i;

        void print_var()
        {
            for (i = 0; i < 3; ++i)
            {
                cout << i << '\n';
            }
        }

        int main()
        {
            for (i = 0; i < 3; ++i)
            {
                print_var();
            }
        }

        /*
        0
        1
        2
        */
        ```

    === "範例 2"

        ```cpp
        #include <iostream>
        using namespace std;

        void print_var()
        {
            for (int i = 0; i < 3; ++i)
            {
                cout << i << '\n';
            }
        }

        int main()
        {
            for (int i = 0; i < 3; ++i)
            {
                print_var();
            }
        }

        /*
        0
        1
        2
        0
        1
        2
        0
        1
        2
        */
        ```

### 覆蓋
當範圍不同的變數同名時，範圍小的會覆蓋範圍大的。

```cpp
#include <iostream>
using namespace std;

int main()
{
    int num = 5;
    for (int i = 0; i < 1; ++i)
    {
        int num = 10;
        cout << num << '\n';
    }
}

/*
10
*/
```

### `static` 關鍵字
如果一個函式內部的變數前面加上 `static` 關鍵字，那麼這個變數就會在程式一開始就會放在記憶體固定的位置上，只到程式結束才消失，而不是隨著函式結束而消失。

```cpp
#include <iostream>
using namespace std;

void addSum(int i)
{
    static int sum = 0;
    sum += i;
    cout << "The current sum is: " << sum << '\n';
}

int main()
{
    for (int i = 1; i <= 5; ++i)
    {
        addSum(i);
    }
}

/*
The current sum is: 1
The current sum is: 3
The current sum is: 6
The current sum is: 10
The current sum is: 15
*/
```

## 遞迴

遞迴是指一種解決問題的辦法，遞迴會先將問題拆解成數個相似的子問題，解決子問題後，再透過子問題的結果將問題解決。在函式中，可以呼叫相同的函式帶有不同的參數，這個特性可以應用在遞迴上，因此可以利用函式實作遞迴。遞迴有兩個要件：

- 終止條件
- 縮小問題的方式

以階乘為例：$$n!=\left\{\begin{array}{}1 && if\ i\leq 1\ (終止條件)\\ n\times (n-1)! && else\ (縮小問題的方式)\end{array}\right.$$

```cpp
int factorial(int i) {
  if (i <= 1) {
    return 1;
  }
  int ans;
  ans = factorial(i - 1);
  ans *= i;
  return ans;
}
```

除了階乘之外，還有許多遞迴的基礎題

- 費式數列
- 河內塔
- 最大公因數

[^1]: [如何撰寫函式 (Function) - Michael Chen 的技術文件](https://michaelchen.tech/c-programming/function/)
[^2]: [函式簡介 - openhome.cc](https://openhome.cc/Gossip/CppGossip/FunctionABC.html)
[^3]: [遞迴 - openhome.cc](https://openhome.cc/Gossip/CGossip/Recursion.html)
[^4]: [變數範圍 - openhome.cc](https://openhome.cc/Gossip/CppGossip/Scope.html)
