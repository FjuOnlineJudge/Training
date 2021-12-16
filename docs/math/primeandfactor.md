# 質數與因數

## 質數

質數為因數只有 $1$ 和自己的數，質數問題在程式競賽中常常遇到，通會建立質數表來查詢質數。

### 一般篩法

每找到一個質數 $x$ ，就知道 $2x, 3x, 4x...$ 都不是質數，把他們從候選名單剃除。

```cpp
--8<-- "docs/math/code/sieve1.cpp"
```

複雜度可到 $O(N\log\log N)$ ，如果不從平方開始剃除，則會退化至 $O(N\log N)$ 

### 線性篩法

每個合數都只被其最小質因數剔除，此算法時間複雜度為 $O(N)$ 。

```cpp
--8<-- "docs/math/code/sieve2.cpp"
```

程式碼關鍵在於 `if (i % p[j] == 0)` ，由於 $p$ 裡面的元素都是遞增的，當這行成立，代表 $i$ 的 $p[j]$ 最小質數， $i\cdot p[j+1], i\cdot p[j+2], ...$ 都是 $p[j]$ 的倍數，都已經被 $p[j]$ 剔除（例如： $9$ 的最小質因數為 $3$ ， $9\cdot 5,9\cdot 7$ 都是 $3$ 的倍數，他們會被 $3$ 剔除），因此不必再篩下去。

## 因數

我們能將任意一個正整數做質因數分解，形式為 $N=P_{1}^{x_{1}}P_{2}^{x_{2}}P_{3}^{x_{3}}...=\Pi P_{i}^{x_{i}}$ ，根據此形式，我們可以求出任一正整數的因數個數及因數總和

- 因數個數： $(x_{1}+1)(x_{2}+1)(x_{3}+1)...=\Pi (x_{i}+1)$ 
- 因數總和： $(P_{1}^{0}+P_{1}^{1}+...+P_{1}^{x_{1}})(P_{2}^{0}+P_{2}^{1}+...+P_{2}^{x_{2}})...=\Pi\Sigma_{j=0}^{x_{i}}(P_{i}^{j})$ 

## 最大公因數

最大公因數 (Greatest Common Divisor, GCD)，可以用輾轉相除法求得。

```cpp
--8<-- "docs/math/code/gcd.cpp"
```

複雜度為 $O(\log(min(a,b)))$ ，最慘狀況發生在兩數為費式數列相鄰項時， `C++<algorithm>` 有內建的 `__gcd` 可以用。

最小公倍數 (Least Common Multiple,LCM)，則為兩數相乘再除以他們的 GCD，為避免溢位狀況，可先將一數除以 GCD，再乘以另外一數。

## 質因數分解

???+ "質因數分解"
    給定一個數字 $N$ ，請列出他的所有質數。

質因數是一道常見的題目，以下有幾個要點：

- 只要枚舉所有 $\leq\sqrt{N}$ 的質數。
-  $N$ 在質因數分解的過程中會一直被更新，當找到 $N$ 的一個質數 $p$ ，請將 $N$ 除以 $p$ 得到新的 $N$ ，縮小搜尋範圍，若是新的 $N$ 還可被 $p$ 整除，重複上述動作，直到 $N$ 無法被 $p$ 整除。
- 最後再檢查 $N$ 是否為 $1$ ，若不是，則 $N$ 也是質數。

```cpp
--8<-- "docs/math/code/primeFactorization.cpp"
```

## 歌德巴赫猜想
- 強歌德巴赫猜想：任何 $>2$ 的偶數都可以寫成兩個質數的和。
- 弱歌德巴赫猜想：任何 $>7$ 的奇數都可以寫成三個質數的和。

???+ Question "UVa 00543 - Goldbach's Conjecture"
    把偶數 $N(6\le N\le 10^6)$ 寫成兩個質數的和。

歌德巴赫猜想基本練習，建立質數表，從頭開始枚舉奇數 $x$，判斷 $x$ 和 $n-x$ 是否皆為質數。

??? "參考程式碼"

    ```cpp
    --8<-- "docs/math/code/uva00543.cpp"
    ```

???+ Question "CodeForces 735D - Taxes"
    給定整數 $N$，求 $N$ 最少可以拆成多少個質數的和。

- 如果 $N$ 是質數，則答案為 $1$。
- 如果 $N$ 是偶數(不包含 $2$)，則答案為 $2$(強歌德巴赫猜想)。
- 如果 $N$ 是奇數且 $N-2$ 是質數，則答案為 $2$(2 + 質數)。
- 其他狀況答案為 $3$(弱歌德巴赫猜想)。

??? "參考程式碼"

    ```cpp
    --8<-- "docs/math/code/cf735D.cpp"
    ```


## 例題練習

-   質數篩法
    -  [UVa 406 - Prime Cuts](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=347) 
    - 只要先求出最大數的平方根內的質數： [UVa 10140 - Prime Distance](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1081) 
-   質因數分解
    -  [Zerojudge a010: 因數分解](https://zerojudge.tw/ShowProblem?problemid=a010) 
