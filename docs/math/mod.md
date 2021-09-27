# 模

取餘數。

## 性質

- 加法： $(a+b) \operatorname{mod} p= (a \operatorname{mod} p +b \operatorname{mod} p ) \operatorname{mod} p$ 
- 減法： $(a-b) \operatorname{mod} p= (a \operatorname{mod} p -b \operatorname{mod} p +p) \operatorname{mod} p$ 
- 乘法： $(a*b) \operatorname{mod} p= (a \operatorname{mod} p\cdot b \operatorname{mod} p ) \operatorname{mod} p$ 
- 次方： $(a^b) \operatorname{mod} p= ((a \operatorname{mod} p )^b) \operatorname{mod} p$ 
- 加法結合律： $((a+b) \operatorname{mod} p+c) \operatorname{mod} p = (a+(b+c)) \operatorname{mod} p$ 
- 乘法結合律： $((a\cdot b) \operatorname{mod} p\cdot c) \operatorname{mod} p = (a\cdot (b\cdot c)) \operatorname{mod} p$ 
- 加法交換律： $(a+b) \operatorname{mod} p=(b+a) \operatorname{mod} p$ 
- 乘法交換律： $(a\cdot b) \operatorname{mod} p=(b\cdot a) \operatorname{mod} p$ 
- 結合律： $((a+b) \operatorname{mod} p\cdot c)= ((a\cdot c) \operatorname{mod} p +(b\cdot c) \operatorname{mod} p ) \operatorname{mod} p$ 

## 同餘

如果 $a\equiv b (\operatorname{mod} m)$ ，我們會說 $a,b$ 在模 $m$ 下同餘。

以下為性質：

- 整除性： $a\equiv b \quad (\operatorname{mod} m) \Rightarrow c \cdot m  = a - b , c \in \mathbb{Z}\\\Rightarrow a \equiv b\quad ( \operatorname{mod} m ) \Rightarrow m \; | \; a-b$ 
- 遞移性：若 $a \equiv b \quad (\operatorname{mod} c) , b \equiv d \quad (\operatorname{mod} c)\\ 則\ a \equiv d (\operatorname{mod} c)$ 
-   保持基本運算：
    $$
    \left \{ \begin{matrix} a \equiv b (\operatorname{mod} m)\\ c \equiv d (\operatorname{mod} m)\end{matrix}\right. \Rightarrow \left\{\begin{matrix}a \pm c \equiv b \pm d (\operatorname{mod} m)\\ a \cdot c \equiv b \cdot d (\operatorname{mod} m)\end{matrix}\right.
    $$
- 放大縮小模數： $k \in \mathbb{Z}^+ , a \equiv b \quad (\operatorname{mod} m) \Leftrightarrow k \cdot a \equiv k \cdot b \quad (\operatorname{mod} k \cdot m)$ 

## 快速冪

我們常常遇到求 $a^b mod\ c$ 為多少的題目，最簡單的作法是用迴圈花 $b$ 次算出答案，但是在 $b$ 很大時就無法快速算出。這時如果拆成 $a^1,a^2,a^4,...,a^{2^x}$ ，先分別計算在乘起來，這樣只要花費 $O(\log b)$ 的時間即可。

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

模逆元是取模下的反元素，即為找到 $a^{-1}$ 使得 $aa^{-1}\equiv\ 1\operatorname{mod} c$ 。

整數 $a$ 在 $\operatorname{mod} c$ 下要有模反元素的充分必要條件為 $a,c$ 互質。

模逆元如果存在會有無限個，任意兩相鄰模逆元相差 $c$ 。

### 方法一：擴展歐基里德演算法

???+ "貝祖定理"
    令 $a,c$ 為非 $0$ 整數，存在整數解 $x,y$ 使得 $ax+cy=gcd(a,c)$ 

從上文可得知，如果 $gcd(a,c)=1$ ，則 $a$ 在 $\operatorname{mod} c$ 下有模反元素，又根據貝祖定理，可知存在整數 $x,y$ ，使得 $ax+cy=gcd(a,c)=1$ ，這裡的 $x$ 即為 $a$ 的反元素。我們可以修改找最大公因數的辦法，找出 $a$ 的模逆元，這個算法稱為擴展歐基里德演算法。這個演算法可以推廣到 $ax+cy=d,d\in\mathbb{Z}$ 

```cpp
// ax+by=c
int extgcd(int a, int b, int c, int &x, int &y) {
  int d = a;
  if (b) {
    d = extgcd(b, a % b, c, y, x);
    y -= (a / b) * x;
  } else {
    x = c;
    y = 0;
  }
  return d;
}
```

### 方法二：快速冪

根據歐拉定理，如果 $gcd(a,c)=1$ ，則 $a^{\Phi(c)} \equiv 1 (\mod c)$ ，將式子稍微改變一下，我們得出 $aa^{\Phi(c)-1} \equiv 1 (\operatorname{mod} c)$ ， $a^{\Phi(c)-1}$ 是 $a$ 在 $\operatorname{mod} c$ 下的一個模逆元。可以利用快速冪計算 $a^{\Phi(c)-1}\operatorname{mod} c$ 算出模逆元。

## 中國剩餘定理

中國剩餘定理，又稱中國餘數定理，是數論中的一個關於一元線性同餘方程組的定理。用來解決像下面這種問題：

"有物不知其數，三三數之剩二，五五數之剩三，七七數之剩二。問物幾何？"，這題答案為 $23+105n,n>=0$ 

列出這種問題的式子（設 $m_i$ 兩兩互質）：

$$
\left \{ \begin{matrix} X\equiv r_1 (\operatorname{mod} m_1)\\ X\equiv r_2 (\operatorname{mod} m_2)\\ \cdot \\ \cdot \\ X\equiv r_n (\operatorname{mod} m_n)\end{matrix}\right.
$$

解決這類問題最簡單是用枚舉來求解，不過如果範圍太大就會吃 TLE 了。因此我們先列出 $n$ 個數字 $ans_1,ans_2,...,ans_n$ :

$$
\left \{ \begin{matrix} ans_1\equiv r_1 (\operatorname{mod} m_1)\\ ans_1\equiv 0 (\operatorname{mod} m_2)\\ \cdot \\ \cdot \\ ans_1\equiv 0 (\operatorname{mod} m_n)\end{matrix}\right.
$$

$$
\left \{ \begin{matrix} ans_2\equiv 0 (\operatorname{mod} m_1)\\ ans_2\equiv r_2 (\operatorname{mod} m_2)\\ \cdot \\ \cdot \\ ans_2\equiv 0 (\operatorname{mod} m_n)\end{matrix}\right.
$$

$$
...
$$

$$
\left \{ \begin{matrix} ans_n\equiv 0 (\operatorname{mod} m_1)\\ ans_n\equiv 0 (\operatorname{mod} m_2)\\ \cdot \\ \cdot \\ ans_n\equiv r_n (\operatorname{mod} m_n)\end{matrix}\right.
$$

分別算出答案後，根據加法在模運算下的性質， $n$ 個數字的和，正是我們想要的答案。

將題目分成 $n$ 個式子後，難度一下降低許多，現在我們只要會解開每個式子就行了。以下以 $ans_1$ 為例：

 $ans_1$ 顯然整除 $m_2,...,m_n$ ，令 $Y_1=\frac{\Pi_{i=1}^{n} m_i}{m_1}$ ，可列出式子 $ans_1=Y_1Z_1\equiv r_1 (\operatorname{mod} m_1)$ 。於是原式就變成找模逆元的問題。

```cpp
LL P = 1, ans = 0;
for (int i = 0; i < n; ++i)
  P *= m[i];
for (int i = 0; i < n; ++i) {
  LL a = P / m[i], x, y;
  extgcd(a, m[i], x, y);
  ans = (ans + r[i] * a * x) % P;
}
cout << (ans + P) % P << '\n';
```

## 例題練習

-   快速冪
    -  [UVa 11609 - Teams](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2656) 
-   模逆元
    -  [Zerojudge a289: Modular Multiplicative Inverse](https://zerojudge.tw/ShowProblem?problemid=a289) 
-   中國剩餘定理
    -  [Zerojudge c641: 滿滿的糖果屋 #2](https://zerojudge.tw/ShowProblem?problemid=c641) （備註：這一題王老師帶的錢必定能買至少一顆糖果）

[^1]:  [Discrete mathematics - Chinese Remainder Theorem](https://wangwilly.github.io/willywangkaa/2018/05/08/Discrete-mathematics-Chinese-Remainder-Theorem/) 
