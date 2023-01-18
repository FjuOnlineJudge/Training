# 數位 DP (位數 DP)

從 $1$ 到 $N$ 有多少數字滿足題目條件。

常見的狀態維度為 (1) 前 $i$ 位數 (2) 最後一位放的數字 (3) 前 $i$ 位數是否和 $N$ 的前 $i$ 位一致。

題目變形，詢問 $[L,R]$ 之間有多少數字滿足題目條件：分別做 $[1,R]$ 和 $[1,L-1]$ 的結果再相減。

???+ Question "AtCoder Beginner Contest 154E – Almost Everywhere Zero"
    $1$ 到 $N$ 中有幾個數字包含 $K$ 個非 $0$ 數字。

- 狀態：$dp[i][j][k]$ 代表前 $i$ 位數，有 $j$ 個非 $0$ 數字，$k=0$ 代表前 $i$ 位剛好是 $N$ 的前 $i$ 位的狀況，$k=1$ 則為至少一位數小於 N 的相對位數的狀況，。
- 初始狀態：$dp[0][0][0]=1$
- 轉移：假設現在要填入 $x$。
    - $i=i+1$
    - 如果 $x=0$，$j=j+1$，否則不變。
    - $k=(k==0) \&\& (x<d[i])$
    - 如果 $k==0$ 且 $x>d[i]$，$x$ 是非法的。

第三個狀態用來判斷第 $i$ 位數的合法範圍：

- 假設 $N=12345$
    - 如果前 $4$ 位數字為 $1234$，第 $5$ 位數可以是 $0~5$
    - 如果前 $4$ 位數字為 $1224$，第 $5$ 位數可以是 $0~9$
- 現在要填入第 $i$ 位，$N=d_0\times 10^0+d_1\times 10^1+d_2\times 10^2+...$
    - 如果前 $i-1$ 位數字和 $N$ 的前 $i-1$ 位數字相同，第 $5$ 位數可以是 $0~d_i$。
    - 如果前 $i-1$ 位數字和 $N$ 的前 $i-1$ 位數字不同，第 $5$ 位數可以是 $0~9$。

??? "參考程式碼"
    ```cpp
    --8<-- "docs/dynamicProgramming/code/abc154E.cpp"
    ```

???+ Question "AtCoder Educational DP Contest S"
    問從 $1$ 到 $N$ 中，用十位數表示，位數和是 $D$ 的倍數得有多少數字。

- 狀態：$f(i,j,k)=$ $i$ 位數數字，對 $D$ 取餘數結果為 $j$，前 $i$ 位數和 $N$ 的前 $i$ 位數 ($k=0$ 不同，$k=1$ 相同)，有幾個數字 
- 轉移：假設現在要填入 $x$。
    - $i=i+1$
    - $j=(j+x)\% D$
    - $k=(k==1) \&\& (x==d[i])$
    - 如果 $k==1$ 且 $x>d[i]$，$x$ 是非法的。