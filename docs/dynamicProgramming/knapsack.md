# 背包 DP (Knapsack DP)

## 0-1 背包問題

???+ Question "0-1 背包問題"

    給定 $N$ 個物品的重量 $w_i$ 和價值 $v_i$，和一個容量為 $W$ 的背包。選取若干件物品放入背包，在不超過背包容量的情況下，背包內物品價值總和最大為何?

每種物品有兩個狀態不放與放，可對應二進位的 $0$ 和 $1$ ，故稱為「0-1 背包問題」。

題目有三項資料，物品個數、物品重量、物品價值，利用這些資料設計出狀態式：

- 狀態： $f(i,j)$ 代表前 $i$ 樣物品在重量總和 $\leq j$ 的情況下，物品價值總和最大值。
- 初始狀態： $f(i,j)=0,\ if\ i = 0$ 。

當算好 $i-1$ 個物品的狀態，對於第 $i$ 個物品有兩種選擇

- 不放：重量和價值不變 $\to$  $f(i,j)=f(i-1,j)$ 。
- 放：重量 $+w_i$ ，價值 $+v_i$  $\to f(i,j)=f(i-1,j-w_i)+v_i$ 。

轉移式就由上面兩種選擇歸納出：

-  $f(i,j)=max(f(i-1,j),f(i-1,j-w_i)+v_i)$ 。

以下為利用二維陣列儲存答案的範例：

```cpp
--8<-- "docs/dynamicProgramming/code/knapsack1.cpp"
```

### 滾動陣列

空間複雜度 $O(NW)$ ，採用「滾動陣列」，可以降低空間複雜度

![](images/knapsack01.png)

由上圖可得知，當在計算 $f(i,j)$ 時，只會用到上一列的資料，因此我們的需要陣列大小降到 $2\times W$ 。

```cpp
--8<-- "docs/dynamicProgramming/code/knapsack2.cpp"
```

再來，如果我們將 $f(i,j)$ 當中的 $j$ 由大到小計算。

![](images/knapsack02.png)

會發現計算 $f(i,j)$ 時， $f(i-1,j),f(i-1,j+1),f(i-1,j+2),...,f(i-1,C)$ 也不會用到，可以將 $f(i,j),f(i,j+1),f(i,j+2),...,f(i,W)$ 覆蓋到 $f(i-1,j),f(i-1,j+1),f(i-1,j+2),...,f(i-1,W)$ 上面。我們可以再次縮小陣列，變成大小為 $W$ 的一維陣列。

```cpp
--8<-- "docs/dynamicProgramming/code/knapsack3.cpp"
```

???+ Tip "滾動陣列"
    覆蓋不會用到的資訊，降低記憶體使用量。

0-1 背包問題時間複雜度 $O(NW)$ ，空間複雜度 $O(N)$ 。

???+ Question "UVa 10664 - Luggage"
    給定 $N$ 樣物品，每件物品的重量為 $w_i$，問可不可以將物品分成等重的兩堆。

需要用 `stringstream` 處裡輸入。

假設總重 $W$，如果 $W$ 為奇數無解，否則用 0/1 背包 DP 判斷是否可以拿總重 $=W/2$ 的物品。

???+ Question "[AtCoder Educational DP Contest E - Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e)"
    承 0/1 背包 DP，$W$ 範圍在 $[1,10^9]$。
        
原本的狀態式會超過時間限制，用價值取代重量當作狀態，再間接取得答案。

- 狀態： $f(i,j)$ 代表前 $i$ 樣物品在價值總和為 $j$ 的情況下，重量總和最小值。
- 初始狀態： $f(i,0)=0,\ where\ 0\leq 1< n,else\ f(i,j)=\infty$ 。
- 轉移：$f(i,j)=min(f(i-1,j),f(i-1,j-v_i)+w_i)$ 

最後找出：$max\{i|f(n,i)\leq w\}$ 

???+ Tip "技巧：表示(負)無限大"

    (負)無限大只要設成一個比最大(小)答案還要大(小)的值就行了。

???+ Question "UVa 10616 - Divisible Group Sums"
    給定 $N$ 個數字，求取 $M$ 個數字總和為 $D$ 的倍數的方法數。

先將所有數字對 $D$ 取餘數(負數 $x$：$x\%D+D$)。

- 狀態：$f(i,j,k)=$ 前 $i$ 個數字取 $j$ 個數字 $=k$ 的方法數。
- 答案 $=f(N,M,0)+f(N,M,D)+f(N,M,2D)+...$

## 無限背包問題

???+ Question "無限背包問題"

    給定 $n$ 種物品的重量 $w_i$ 和價值 $v_i$，和一個容量為 $W$ 的背包。每種物品可選取任意個放入背包，在不超過背包容量的情況下，背包內物品價值總和最大為何?

無限背包問題和 0-1 背包問題的狀態式相同，以下為轉移式：

-  $f(i,j)=max(f(i-1,j-k\times w_i)+ k\times v_i), \forall k\times w_i\leq j$ 

可以簡化成：

-  $f(i,j)=max(f(i-1,j),f(i-1,j-w_i)+v_i,f(i,j-w_i)+v_i)$ 。
-  $f(i,j)=max(f(i-1,j),max(f(i-1,j-w_i),f(i,j-w_i)+)v_i)$ 。

為什麼可以這樣優化？是因為當 $f(i,j)$ 當中的 $j$ 由小到大計算時， $f(i,j-w_i)$ 已被 $f(i,j-2\times w_i)$ 更新過，那麼 $f(i,j-w_i)$ 就是選擇第 $i$ 種物品數次的最佳結果。

> 換言之，我們通過局部最優子結構的性質重複使用了之前的枚舉過程，優化了枚舉的複雜度。(from [背包 DP - OI Wiki](https://oi-wiki.org/dp/knapsack/) )

下面為範例程式碼，一樣有用到滾動陣列的技巧：

```cpp
--8<-- "docs/dynamicProgramming/code/knapsack4.cpp"
```

無限背包問題時間複雜度 $O(NW)$ ，空間複雜度 $O(W)$ 。

???+ Question "UVa 00674 - Coin Change"
    有 $C=[1,5,10,25,50]$ 五種硬幣，有多少種方法湊出 $N$ 元?

- 狀態： $f(i,j)$ 前 $i$ 種硬幣才能湊出 $N$ 元的方法數
- 初始狀態：$f(0,0)=1$
- 轉移：$f(i,j)=f(i-1,j)+f(i,j-c_i)$

```cpp
--8<-- "docs/dynamicProgramming/code/uva00674.cpp"
```

???+ Question "UVa 12955 - Factorial"
    給定一個數字 $N$，最少可以使用幾個 $x!$ 的和表示?

和 UVa 00674 - Coin Change 相似，幣值改成 $1!,2!,3!,...$。

## 二維背包問題

限制變為兩項。

???+ Question "HDU - 2159 FATE"
    打怪遊戲，每種怪物有忍耐度 $t_i$ 和經驗值 $e_i$，給定數量和忍耐度限制，是否可以獲得至少 $N$ 經驗值?

- 狀態：$f(i,j,k)$：在前 $i$ 種怪物選 $\le j$ 隻攻擊，忍耐度 $\le k$ 的情況下的最大經驗值。
- 初始狀態：$f(0,j,k)=0$
- 轉移：$f(i,j,k)=max(f(i-1,j,k),f(i,j-1,k-t_i)+e_i)$

???+ Question "OpenJ_Bailian 1948 - Triangular Pastures"
    給定 $N$ 根棍子，第 $i$ 根棍子長度為 $h_i$，問 $N$ 根棍子組成最大三角形面積為何(每根棍子都要用到)?

先用動態規劃找出所有可能。

- 狀態：$f(i,j,k)$ 前 $i$ 根棍子是否可以形成第一條邊長為 $i$，第二條邊長為 $j$ 的情況。
    - boolean 函數
- 初始狀態：$f(0,0,0)=true$。
- 轉移式子：$f(i,j,k)= (j-h_i>0\ and\ f(i,j-h_i,k))\ or\ (k-h_i>0\ and\ f(i,j,k-h_i))$。
    - 試著把第 $i$ 根棍子放到第一條邊或第二條邊。

枚舉三邊長 $i,j,k$，邊長最大為棍子和 $/2$，檢查是否有解，如果有解更新最大面積。

## 例題練習

-   0-1 背包問題 
    -  [UVa 10130 - SuperSale](http://uva.onlinejudge.org/external/101/10130.pdf) 
    -  [AtCoder Educational DP Contest D - Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d) 
-   無限背包問題
    -  [UVa 10465 - Homer Simpson](http://uva.onlinejudge.org/external/104/10465.pdf)
    -  [UVa 00357 - Let Me Count The Ways](http://uva.onlinejudge.org/external/3/357.pdf) 
