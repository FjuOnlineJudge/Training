# 倍增

把線性查詢的時間複雜度優化到對數等級。

## 步驟

假設序列長度 $=N$，$f[i][j]$ 代表 $i$ 經過 $2^j$ 轉換的結果。第一維大小 $>=N$，第二維大小 $>=\log N$。

- 初始化：算出所有 $f[i][0]$。
- 動態規劃：算出所有 $f[i][j],\forall j>0$。
- 二分搜查詢：利用 $f$ 的結果算出答案。

## AtCoder Regular Contest 060 C

???+ Question "AtCoder Regular Contest 060 C - Tak and Hotels"
    $i$ 號旅館位置為 $x_i$，$1\le x_1<x_2<...<x_n\le 10^9$，一天可以走 $L$ 單位，問從 $a$ 號旅館走到 $b$ 號旅館要幾天。

令 $ans[i][j]=$ 從旅館 $i$ 走 $2^j$ 天最遠可以走到幾號旅館，先用二分搜求出從每家旅館走 $1$ 天最遠可以走到幾號旅館，接著用動態規劃算出其他答案，在查詢的時候，二分搜找到 $a$ 最多走幾天依然不會到 $b$，這樣比起直接找 $a$ 走到 $b$ 要花幾天比較容易，最後把結果 $+1$ 就是答案。

```cpp
--8<-- "docs/algorithm/code/arc060C.cpp"
```

## Codeforces 1175E

???+ Question "Codeforces 1175E - Minimal Segment Cover"
    給定 $N$ 個區間 $[L_x,R_x]$ 和 $Q$ 筆詢問，詢問至少要多少區間才能覆蓋 $[x,y]$。

令 $ans[i][j]$：從 $i$ 開始經過幾個 $2^j$ 區間能抵達的最大右界，$ans[i][0]$ 為包含 $i$ 的所有區間最大的右界，在實作上會分成左界 $=i$ 和左界 $<i$ 分開處裡，先處理左界 $=i$ 的情況：$ans[i][0]=max{R_x|L_x=i}$；再處理左界 $<i$ 的情況，也就是 $max(ans[1][0],ans[2][0],...,ans[i-1][0])$，這裡用到前綴的技巧：$ans[i][0]=max(ans[i-1][0],ans[i][0])$。

二分搜的部分會搜尋 $x$ 最多經過幾個區間依然不會到達 $y$。

## 應用

- [Sparse Table](../../dataStructure/sparetable/)
- [最低共同祖先](../../graph/lca)
- [快速冪](../../math/mod/#_4)