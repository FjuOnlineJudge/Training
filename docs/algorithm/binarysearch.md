# 二分搜

對於一個函數 $F(n)$ ，如果存在一個 x，對於所有 $\geq x$ 的 a， $F(a)=$ true，反之 $F(a)=$ false，基於這樣的單調性，就可以用二分搜。

```cpp
--8<-- "docs/algorithm/code/binarySearch.cpp"
```


二分搜要注意兩件事，一個是無限迴圈，要避免它可以在腦中先模擬一下。一個是在實數中二分搜，因為實數的稠密性，題目會有誤差容忍值（例如 $10^{-6}$ )，只要在誤差內都是容許的。

## 有序序列二分搜

對排列好的序列，可直接使用 `lower_bound` 和 `upper_bound`。

```cpp
lower_bound(a, a + n, k);     //最左邊 ≥ k 的位置
upper_bound(a, a + n, k);     //最左邊 > k 的位置
upper_bound(a, a + n, k) - 1; //最右邊 ≤ k 的位置
lower_bound(a, a + n, k) - 1; //最右邊 < k 的位置
[lower_bound, upper_bound) //等於 k 的範圍
equal_range(a, a+n, k);
```


???+ Question "UVa 10474 - Where is the Marble?"

    給定一組數字，先將它們排序後，詢問數字 $x$，在第幾個位置。

二分搜基本練習。

??? "參考程式碼"

    ```cpp
    --8<-- "docs/algorithm/code/uva10474.cpp"
    ```

???+ Question "UVa 11057 - Exact Sum"

    給定一組數字，找出兩個數字，數字和為 $M$，如果有多組解，輸出差距最小的一組。

先對序列排序，枚舉每個數字 $x$，利用二分搜判斷是否存在 $M-x$。

??? "參考程式碼"

    ```cpp
    --8<-- "docs/algorithm/code/uva10157.cpp"
    ```

## 對答案二分搜

有些題目為 "最多/最少為何會成立"，那麼如果你可以在良好的時間檢查出 " 如果代價是 $x$ ，那可不可以達成目標 "，並且 $x$ 具有單調性，那麼你可以轉換成 " $F(x)=$ 如果代價是 $x$ ，那可不可以達成目標 "，對答案（$x$）進行二分搜。

???+ Question "UVa 12032 - The Monkey and the Oiled Bamboo"

    一開始位置在 $0$，依序抵達座標 $r_1,r_2,...,r_n$，找出最小的 $k$ 滿足：每一次最多只能前進 $k$ 步，如果這次前進 $k$ 步，之後最多只能前進 $k-1$ 步，以此類推。

二分搜答案 $k$，$F(x)$ 代表一開始 $k=x$ 是否可以題目要求，利用題目敘述實現 $F(x)$

??? "參考程式碼"

    ```cpp
    --8<-- "docs/algorithm/code/uva12032.cpp"
    ```

???+ Question "UVa 11413 - Fill the Containers"

    給定 $N$ 個數字 $a_1,a_2,...,a_N$，要把它切割成 $M$ 組數字，第 $i$ 組數字和為 $sum_i$，切割成本 $cost=max\ sum_i$，請求出最小的 $cost$。

這題設 $F(x)$ 為成本是否可以 $\le x$，$F(x)$ 的判斷方法為：從頭開始取數字，每一組盡可能累積到 $X$，取完 $M$ 組後，看是否還有數字未取到。

??? "參考程式碼"

    ```cpp
    --8<-- "docs/algorithm/code/uva11413.cpp"
    ```

???+ Question "UVa 12190 - Electric Bill"

    給定電力價格表，你和你的鄰居合併計算電費為 $A$ 元，分開計算的差額為 $B$ 元，請問如果分開計算的情況下，你的電費為何(你的電費比較便宜)?

設 $Bill(a)$ 計算使用 $a$ 度電的電費，先用二分搜找出兩個人總共使用的電量 $tot$，接著找出你的電量 $x$，有以下三種情況：

- 如果 $Bill(total-x)-Bill(x)==B$，輸出 $x$
- 如果 $Bill(total-x)-Bill(x)<B$，$R=x-1$
- 否則 $L=x+1$ 

??? "參考程式碼"

    ```cpp
    --8<-- "docs/algorithm/code/uva12190.cpp"
    ```

## 最小瓶頸樹

???+ Question "最小瓶頸樹"

    給定一張圖，求一顆生成樹，樹的最大邊權值最小。

枚舉最大邊權值 $w$ ，用 DFS/BFS 檢查 $\leq w$ 的邊是否可以將所有點相連，如果可以，最大邊權值會 $\leq w$ ，否則會 $>w$ 。

## 三分搜

對於凸函數（例如 $y=F(x)=x^2$ )，我們想要找尋其極值，意謂其左右兩側皆各自遞增/遞減，我們可以利用三分搜來解決（二分搜只能解決全體單調性，不能解決有兩邊的）。
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
--8<-- "docs/algorithm/code/trinarySearch1.cpp"
```

另外一種做法，會固定迴圈迭代次數。

```cpp
--8<-- "docs/algorithm/code/trinarySearch2.cpp"
```

???+ Question "UVa 01476 - Error Curves"
    給定 $N$ 個開口向上的二次曲線 $S_i$，令 $F(x)=max{S_i(x)}$，求 $F(x)$ 的最小值。

多個二次函數取最大值的結果還是一個二次函數，利用三分搜搜尋極值。

??? "參考程式碼"

    ```cpp
    --8<-- "docs/algorithm/code/uva01476.cpp"
    ```

???+ Question "UVa 10385 - Duathlon"
    今天有 $N$ 個人要參加鐵人二項，有跑步和騎腳踏車，總長 $L$ 公里，第 $N$ 位參賽者賄賂主辦方，想要得到第一名，主辦方知道每個人跑步和騎腳踏車的速度 $vr_i,vk_i$，並且可以隨意決定跑步和騎腳踏車的距離，求第 $N$ 位參賽者是否能獲得第一，如果可以，輸出領先第二名的秒數和主辦方設定跑步和騎腳踏車的距離。

設跑步 $r$ 公里，那麼騎腳踏車 $L-r$ 公里，第 $i$ 位參賽者要花費 $t_i(r)=\frac{r}{vr_i}+\frac{k}{vk_i}$，前 $N-1$ 位參賽者花費時間取最小值，再減去第 $N$ 位參賽者的時間，會是一個凸函數([可以參考這篇文章](https://blog.csdn.net/mobius_strip/article/details/45629163))，同樣也能用三分搜找出極值

??? "參考程式碼"

    ```cpp
    --8<-- "docs/algorithm/code/uva10385.cpp"
    ```

## 例題練習

-   最小瓶頸樹
    -  [UVa 01395 - Slim Span](https://onlinejudge.org/external/13/1395.pdf) 
