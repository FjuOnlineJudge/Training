# 質數與因數

## 質數

質數為因數只有 $1$ 和自己的數，質數問題在程式競賽中常常遇到，通會建立質數表來查詢質數。

### 一般篩法

每找到一個質數 $x$ ，就知道 $2x, 3x, 4x...$ 都不是質數，把他們從候選名單剃除。

```cpp
vector<int> p;
bitset<MAXN> is_notp;
void PrimeTable(int n) {
  is_notp.reset();
  is_notp[0] = is_notp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (is_notp[i])
      continue;
    p.push_back(i);
    for (int j = i * i; j <= n; j += i) {
      is_notp[j] = 1;
    }
  }
}
```

複雜度可到 $O(N\log\log N)$ ，如果不從平方開始剃除，則會退化至 $O(N\log N)$ 

### 線性篩法

將一般篩法優化至 $O(N)$ ，我們期望每個合數都只被其最小質因數剔除，這樣可以確保其均攤的線性。實作上，我們讓每一個數去替除自己乘上「 **小於等於** 其質因數的所有質數」的數字即可。

```cpp
vector<int> p;
bitset<MAXN> is_notp;
void PrimeTable(int n) {
  is_notp.reset();
  is_notp[0] = is_notp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!is_notp[i])
      p.push_back(i);
    for (int j : p) {
      if (i * j > n)
        break;
      is_notp[i * j] = 1;
      if (i % j == 0)
        break;
    }
  }
}
```

## 因數

我們能將任意一個正整數做質因數分解，形式為 $N=P_{1}^{x_{1}}P_{2}^{x_{2}}P_{3}^{x_{3}}...=\Pi P_{i}^{x_{i}}$ ，根據此形式，我們可以求出任一正整數的因數個數及因數總和

- 因數個數： $(x_{1}+1)(x_{2}+1)(x_{3}+1)...=\Pi (x_{i}+1)$ 
- 因數總和： $(P_{1}^{0}+P_{1}^{1}+...+P_{1}^{x_{1}})(P_{2}^{0}+P_{2}^{1}+...+P_{2}^{x_{2}})...=\Pi\Sigma_{j=0}^{x_{i}}(P_{i}^{j})$ 

## 最大公因數

最大公因數（Greatest Common Divisor, GCD)，可以用輾轉相除法求得。

```cpp
int GCD(int a, int b) {
  if (b == 0)
    return a;
  return GCD(b, a % b);
}
```

複雜度為 $O(\log(min(a,b)))$ ，最慘狀況發生在兩數為費式數列相鄰項時， `C++<algorithm>` 有內建的 `__gcd` 可以用。

最小公倍數（Least Common Multiple,LCM)，則為兩數相乘再除以他們的 GCD，為避免溢位狀況，可先將一數除以 GCD，再乘以另外一數。
