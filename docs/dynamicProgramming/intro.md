# 動態規劃簡介 (Dynamic Programming Intro)

動態規劃 (Dynamic Programming, DP) 和分治法相似，會把問題分解成若干個子問題，不同的是，DP 的子問題往往都是不獨立，子問題需要依靠其他子問題的解。

## 性質
- 重複子問題：相同的一個子問題,會被重複計算多次。
- 最佳子結構：問題的最佳解包含子問題的最佳解。
- 無後效性：子問題一旦確被定後，就不會被改變，不會被之後更大的問題所影響。

???+ "技巧：空間換取時間(記憶化搜索)"
	為避免相同子問題多次計算，會使用陣列(記憶體)記住答案，提高計算效率。

## 步驟
- 定義狀態：要如何記錄問題的答案。通常定義 $f(p_1,p_2,...)$，為算出答案的函數。
- 訂出初始狀態。
- 訂出轉移式：如何從其他狀態轉移到當前狀態。

???+ "時間/空間複雜度計算"
	時間複雜度：狀態個數 $\times$ 轉移複雜度。
	狀態個數絕大多數可由開的陣列大小得知。
	轉移複雜度：最多一個狀態需要花費多少時間計算。

## 費式數列
費式數列的定義：$f(n)=f(n-1)+f(n-2),f(0)=0,f(1)=1$。

DP 設計如下：

- 狀態：$f(n)$ 代表費式數列第 $n$ 項。
- 初始狀態：$f(n)=n\ where\ n\leq 1$。
- 轉移：$f(n)=f(n-1)+f(n-2)$。

下列展示四種計算費式數列的版本：

### 遞迴 (未搭配陣列)

```cpp
int f(int n)
{
    if (n < 2)
    {
        return n;
    }
    return f(n - 1) + f(n - 2);
}
```

這種版本的時間複雜度 $O(n)=f(n-1)$，$f(n)$ 是費式數列第 $n$ 項，時間效率非常低，我們不會使用這種版本實作 DP。

### 遞迴 (搭配陣列)
這種版本建立上個版本的基礎，增加了陣列紀錄已計算出的答案。

```cpp
int dp[30];
int f(int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = f(n - 1) + f(n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    cout << f(25) << '\n';
}
```

一開始將每個 $dp$ 設為 $-1$，代表該狀態未被計算。

???+ "技巧：表示未計算狀態"
	將陣列的數值初始化一個不可能成為答案的數字 (例如：$-1,0$)，代表該狀態未被計算。


這種版本的時間複雜度我們用以下程式碼解釋：

```cpp
int dp[30];
int f(int p, int n)
{
    cout << p << " call " << n << '\n';
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = f(n, n - 1) + f(n, n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    f(-1, 5);
}
```

```
-1 call 5
5 call 4
4 call 3
3 call 2
2 call 1
2 call 0
3 call 1
4 call 2
5 call 3
```

當呼叫 $f(n)$，每個 $f(i), 0\leq i\leq n$，至多會被呼叫兩次，第一次 $f(i)$ 被 $f(i-1)$ 呼叫，這時 $f(i)$ 還沒被計算，因此會繼續遞迴求值；第二次 $f(i)$ 被 $f(i-2)$ 呼叫，這時 $f(i)$ 已被計算，直接回傳結果。

因為每個 $f(i)$ 最多呼叫兩次，時間複雜度為 $O(n)$。

### 迴圈 (往前看)
當前狀態是從那些狀態得到。

```cpp
int main()
{
    int dp[30];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 30;++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[5] << '\n';
}
```


### 迴圈 (往後看)
當前狀態會影響那些狀態。

```cpp
int main()
{
    int dp[30];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 0; i < 30; ++i)
    {
        if (i + 1 < 30)
        {
            dp[i + 1] += dp[i];
        }
        if (i + 2 < 30)
        {
            dp[i + 2] += dp[i];
        }
    }
    cout << dp[5] << '\n';
}
```

???+ "DP 實作辦法"
	- 遞迴
	- 迴圈 (向前看)
	- 迴圈 (向後看)

除了費式數列，任何數列可以寫成 $f(i)=a_1f(i-1)+a_2f(i-2)+...+a_nf(i-n)+k$ 的形式，皆可利用 DP 來解出。

## 帕斯卡三角形 (Pascal's triangle)
帕斯卡三角形的第 $i$ 層第 $j$ 個項 $=C_j^i$，有以下性質：$C^n_k=C_k^{n-1}+C_{k-1}^{n-1}$。

同樣可以用 DP 計算：

- 狀態：$f(i,j)$ 代表帕斯卡三角形的第 $i$ 層第 $j$ 個項。
- 初始狀態：$f(i,j)=1, if\ j==0\ or\ j==i$。
- 轉移：$f(i,j)=f(i-1,j)+f(i-1,j-1)$。

```cpp
int main()
{
    int dp[30][30];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 30; ++i)
    {
        dp[i][0] = dp[i][i] = 1;
    }
    for (int i = 1; i < 30; ++i)
    {
        for (int j = 1; j < 30; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}
```

## [AtCoder Educational DP Contest A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a)
有隻青蛙要從第 $1$ 塊石頭跳到第 $N$ 塊石頭，每塊石頭都有高度 $h_i$，每一次可以從第 $i$ 塊跳到第 $i+1$ 塊，成本為兩塊石頭的高低差，求最小成本。

DP 設計如下：

- 狀態：$f(n)$ 代表從第 $1$ 塊石頭跳到第 $n$ 塊石頭的最小成本。
- 初始狀態：$f(0)=0$。
- 轉移：$f(n)=min(abs(h_{n}-h_{n-1})+f(i-1),abs(h_{n}-h_{n-2})+f(i-2))$。

??? "參考程式碼"
    作者：[allem40306](https://github.com/allem40306)
	```cpp
	int main()
	{
	    int n;
	    cin >> n;
	    vector<int> h(n + 5), dp(n + 5);
	    FOR(i, 0, n) { cin >> h[i]; }
	    fill(dp.begin(), dp.end(), INF);
	    dp[0] = 0;
	    FOR(i, 1, n) FOR(j, 1, 3)
	    {
	        if (i - j < 0)
	        {
	            break;
	        }
	        dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
	    }
	    cout << dp[n - 1] << '\n';
	}
	```


???+ "技巧：$dp[i]=1\to i$ (前綴狀態)"
	一維 DP 常用狀態，經典的例子為前綴和。


## 例題練習

-   數列
    -  [UVa 00900 - Brick Wall Patterns](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=841)
    -  [Zerojudge d212 - 東東爬階梯](https://zerojudge.tw/ShowProblem?problemid=d212) 
-   帕斯卡三角形
    -  [UVa 00825 - Walking on the Safe Side](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=766) 
- [AtCoder Educational DP Contest B - Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b)
- [AtCoder Educational DP Contest C - Vacation](https://atcoder.jp/contests/dp/tasks/dp_c)
