# 模

取餘數。

## 性質

- 加法： $(a+b) \operatorname{mod} p= (a \operatorname{mod} p +b \operatorname{mod} p ) \operatorname{mod} p$ 
- 減法： $(a-b) \operatorname{mod} p= (a \operatorname{mod} p -b \operatorname{mod} p +p) \operatorname{mod} p$ 
- 乘法： $(a*b) \operatorname{mod} p= (a \operatorname{mod} p *b \operatorname{mod} p ) \operatorname{mod} p$ 
- 次方： $(a^b) \operatorname{mod} p= ((a \operatorname{mod} p )^b) \operatorname{mod} p$ 
- 加法結合律： $((a+b) \operatorname{mod} p+c) \operatorname{mod} p = (a+(b+c)) \operatorname{mod} p$ 
- 乘法結合律： $((a*b) \operatorname{mod} p*c) \operatorname{mod} p = (a*(b*c)) \operatorname{mod} p$ 
- 加法交換律： $(a+b) \operatorname{mod} p=(b+a) \operatorname{mod} p$ 
- 乘法交換律： $(a*b) \operatorname{mod} p=(b*a) \operatorname{mod} p$ 
- 結合律： $((a+b) \operatorname{mod} p*c)= ((a*c) \operatorname{mod} p +(b*c) \operatorname{mod} p ) \operatorname{mod} p$ 

## 同餘

如果 $a\equiv b (\operatorname{mod} m)$ ，我們會說 $a,b$ 在模 $m$ 下同餘。

以下為性質：

- 整除性： $a\equiv b \quad (\operatorname{mod} m) \Rightarrow c \cdot m  = a - b , c \in \mathbb{Z}$ \\ $\Rightarrow a \equiv b\quad ( \operatorname{mod} m ) \Rightarrow m \; | \; a-b$ 
- 遞移性：若 $a \equiv b \quad (\operatorname{mod} c) , b \equiv d \quad (\operatorname{mod} c)$ \\則 $a \equiv d (\operatorname{mod} c)$ 
-   保持基本運算：
    $$
    \left \{ \begin{matrix} a \equiv b (\operatorname{mod} m)\\ c \equiv d (\operatorname{mod} m)\end{matrix}\right. \Rightarrow \left\{\begin{matrix}a \pm c \equiv b \pm d (\operatorname{mod} m)\\ a \cdot c \equiv b \cdot d (\operatorname{mod} m)\end{matrix}\right.
    $$
- 放大縮小模數： $k \in \mathbb{Z}^+ , a \equiv b \quad (\operatorname{mod} m) \Leftrightarrow k \cdot a \equiv k \cdot b \quad (\operatorname{mod} k \cdot m)$ 

參考文章： <https://wangwilly.github.io/willywangkaa/2018/05/08/Discrete-mathematics-Chinese-Remainder-Theorem/> 

## 快速冪

我們常常遇到求 $a^b mod\ c$ 為多少的題目，最簡單的作法是用迴圈花 b 次算出答案，但是在 b 很大時就無法快速算出。這時如果拆成 $a^1,a^2,a^4,...,a^{2^x}$ ，先分別計算在乘起來，這樣只要花費 $O(\log b)$ 的時間即可。

```cpp
T pow(int a, int b, int c) { // calculate a^b%c
  T res = 1, tmp = a;
  for (; b; b >>= 1) {
    if (b & 1)
      res = res * tmp % c;
    tmp = tmp * tmp % c;
  }
  return res;
}
```

## 模逆元

模逆元是取模下的反元素，即為找到 $a^{-1}$ 使得 $aa^{-1}\equiv\ 1\ mod\ c$ 。如果 a 要在 mod c 下有反元素，那麼 $gcd(a,c)=1$ ，根據貝祖定理，可知存在整數 $x,y$ ，使得 $ax+cy=gcd(a,c)=1$ ，這裡的 $x$ 即為 a 的反元素，我們可以修改找 GCD 的辦法，找出 $a$ 的反元素。

```cpp
int extgcd(int a, int b, int &x, int &y) {
  int d = a;
  if (b) {
    d = extgcd(b, a % b, y, x);
    y -= -(a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
```
