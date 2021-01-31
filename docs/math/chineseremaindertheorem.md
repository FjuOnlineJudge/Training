# 中國剩餘定理

中國剩餘定理，又稱中國餘數定理，是數論中的一個關於一元線性同餘方程組的定理。用來解決像下面這種問題：

"有物不知其數，三三數之剩二，五五數之剩三，七七數之剩二。問物幾何？"，這題答案為 $23+105n,n>=0$ 

列出這種問題的式子（設 $m_i$ 兩兩互質）：

$$
\left \{ \begin{matrix} X\equiv a_1 (\operatorname{mod} m_1)\\ X\equiv a_2 (\operatorname{mod} m_2)\\ \cdot \\ \cdot \\ X\equiv a_n (\operatorname{mod} m_n)\end{matrix}\right.
$$

解決這類問題最簡單適用枚舉來求解，不過如果範圍太大就會吃 TLE 了。因此我們，我們設 $M=\Pi_{i=1}^{n} m_i$ ，令 $x_1 \operatorname{mod} m_1 \equiv a_1$ ，而對其他 $m_i$ 皆整除，拆解 $x_1$ 成為 $x_1=(M/m_1)r_1$ 亦即 $(M/m_1)r_1\equiv a_1 (\operatorname{mod} m_1)$ ，用找模逆元的方式求出 $x_1$ 。 $x_2,x_3,...,x_n$ 也是依照這個辦法求出，最後 $X=(\Sigma_{i=1}^{n} x_i)\operatorname{mod} M+kM(k>=0)$ 。

總共有 $n$ 個式子，每個式子都要找一次模逆元，所以複雜度為 $O(n \log m)$ 
