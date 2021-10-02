# 二分搜

對於一個函數 $F(n)$ ，如果存在一個 x，對於所有 $\\geq x$ 的 a， $F(a)=$ true，反之 $F(a)=$ false，基於這樣的單調性，就可以用二分搜。

```cpp
T binary_search() {
  while (L < R) {
    int M = (L + R) >> 1;
    if (F(M))
      R = M;
    else
      L = M + 1;
  }
  return L;
}
```

有些題目為 "最多/最少為何會成立"，那麼如果你可以在良好的時間檢查出 " 如果代價是 $x$ ，那可不可以達成目標 "，並且 $x$ 具有單調性，那麼你可以轉換成 " 如果代價是 $x$ ，那可不可以達成目標 " 傳換成 $F(x)$ ，對答案（x）進行二分搜。
二分搜要注意兩件事，一個是無限迴圈，要避免它可以在腦中先模擬一下。一個是在實數中二分搜，因為實數的稠密性，題目會有誤差容忍值（例如 $10^{-6}$ )，只要在誤差內都是容許的。

## 最小瓶頸樹
???+ Question "最小瓶頸樹"
	給定一張圖，求一顆生成樹，樹的最大邊權值最小。

枚舉最大邊權值 $w$，用 DFS/BFS 檢查 $\leq w$ 的邊是否可以將所有點相連，如果可以，最大邊權值會 $\leq w$，否則會 $>w$。

## 三分搜

對於 U 型函數（例如 $y=F(x)=x^2$ )，我們想要找尋其極值，意謂其左右兩側皆各自遞增/遞減，我們可以利用三分搜來解決（二分搜只能解決全體單調性，不能解決有兩邊的）。
考慮三分後從左到右四個採樣點的關係

-  $S(a) < S(b) < S(c) < S(d)$ ，此時最小值一定不在最右邊
-  $S(a) > S(b) < S(c) < S(d)$ ，此時最小值一定不在最右邊
-  $S(a) > S(b) > S(c) < S(d)$ ，此時最小值一定不在最左邊
-  $S(a) > S(b) > S(c) > S(d)$ ，此時最小值一定不在最左邊

這段描敘還可以再簡化：

-  $S(b) < S(c)$ ，此時最小值一定不在最右邊
-  $S(b) > S(c)$ ，此時最小值一定不在最左邊

每次迭代先求出 $b,c$ 的值，再利用簡化過的規則，使區間減少 $\frac{1}{3}$ 。令 $EPS$ 為誤差容忍值，一開始的範圍為 $[L,R]$ ，迴圈大約需迭代 $\log_{1.5}\frac{R-L}{EPS}$ 次（ $\log_{1.5}10$ 大約為 $5.6$ )。

```cpp
const double EPS = 1e−7;
double trinary_search(double L, double R)
{
    while (R - L > EPS)
    {
        double mL = (L + L + R) / 3, mR = (L + R + R) / 3;
        if (f(mR) > f(mL))
            R = mR;
        else
            L = mL;
    }
    return L;
}
```

另外一種做法，會固定迴圈迭代次數。

```cpp
double trinary_search(double L, double R)
{
    for (int i = 0; i < 300; ++i)
    {
        double mL = (L + L + R) / 3, mR = (L + R + R) / 3;
        if (f(mR) > f(mL))
            R = mR;
        else
            L = mL;
    }
    return L;
}
```


## 例題練習

-  最小瓶頸樹
	-  [UVa 01395 - Slim Span](https://onlinejudge.org/external/13/1395.pdf)
-  三分搜
	-  [UVa 01476 - Error Curves](https://onlinejudge.org/external/14/1476.pdf)