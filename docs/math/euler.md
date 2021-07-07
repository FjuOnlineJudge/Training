# 歐拉函數

## 定義

歐拉函數計算對於一個整數 N，小於等於 N 的正整數中，有幾個和 N 互質。通常用 $\Phi(n)$ 表示。

## 性質

-   歐拉函數是一個積性函數: 如果 $gcd(p,q)=1,\Phi(p)\cdot\Phi(q)=\Phi(p\cdot q)$
-   如果 $p$ 是質數： $\Phi(p) = p-1$
-   $\Phi(p^k)=p^{k−1}\times (p−1)$

## 計算

根據上述性質，可整理出一個公式: $\Phi(N)=N\times\Pi_{p|N}(1-\frac{1}{p})$ 。

要計算 $\Phi(n)$，可以利用質因數分解求得。

```cpp
int Phi(int n) {
  int ret = n;
  for (int i : p) {
    if (i * i > n)
      break;
    if (n % i == 0) {
      ret /= i;
      ret *= i - 1;
      while (n % i == 0)
        n /= i;
    }
  }
  if (n != 1) {
    ret /= n;
    ret *= n - 1;
  }
  return ret;
}
```

另一種辦法是利用質數篩法。

```cpp
void phi_table(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (phi[i])
      continue;
    for (int j = i; j < n; j += i) {
      if (!phi[j])
        phi[j] = j;
      phi[j] = phi[j] / i * (i - 1);
    }
  }
}
```

## 相關定理

### 費馬小定理

給定一個質數 $p$ 及一個整數 $a$ ，那麼： $a^p \equiv a (\mod p)$ 如果 $gcd(a,p)=1$ ，則： $a^{p-1} \equiv 1 (\mod p)$ 

### 歐拉定理

歐拉定理是比較 generate 版本的費馬小定理。給定兩個整數 $n$ 和 $a$ ，如果 $gcd(a,n)=1$ ，則 $a^{\Phi(n)} \equiv 1 (\mod n)$ 如果 $n$ 是質數， $\Phi(n)=n-1$ ，也就是費馬小定理。

### Wilson's theorem

給定一個質數 $p$ ，則： $(p-1)!\equiv -1 (\mod p)$ 


## 例題練習

-   歐拉函數
    -    [UVa 10820 - Send a Table](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1761)