# 區間 DP

$f(i,j)$ 代表 $i,i+1,i+2,...,j$ 之間的所有狀態的整合結果。

遞迴和迴圈都是常見實作方法。

```cpp
--8<-- "docs/dynamicProgramming/code/intervalDP.cpp"
```

???+ Question "UVa 10003 - Cutting Sticks"
    有一根木棍長度為 $L$ 要往 $n$ 個點 $p_1,p_2,p_3$ 切開，切木棍的成本 $=$ 木棍長度，問最小成本為多少?

先增加兩個點 $p_0=0,p_{n+1}=L$

- 狀態：$f(i,j)=$ 切開 $[p_i,p_j]$ 這段木棍的最小成本
- 轉移：$f(i,j)=(p_j-p_i)+min\{f(i,k)+f(k,j)|i<k<j\}$

??? "參考程式碼"
    ```cpp
    --8<-- "docs/dynamicProgramming/code/uva10003.cpp"
    ```

???+ Question "矩陣相乘問題"
    兩個矩陣 $A\in R^{x\times y}, B\in R^{y\times z}$ 相乘需要操作 $x\times y\time z$ 次。給定 $N$ 個矩陣 $M_1\in R^{x_1\times x_2},M_2\in R^{x_2\times x_3},M_3\in R^{x_3\times x_4},...,M_N\in R^{x_N\times x_{N +1}}$，矩陣相乘順序不影響結果，請問最少相乘次數為何?

- 狀態：$f(i,j)=$ 從第 $i$ 個矩陣相乘到第 $j$ 個矩陣的最少相乘次數
- 初始狀態：$f(i,i)=0,f(i,i+1)=x_{i}\times x_{i+1}\times x_{i+2}$
- 轉移式子：$f(i,j)=min\{f(i,k)+f(k+1,j)+x_{k}\times x_{k+1}\times x_{k+2}\|i<=k<j\}$

???+ Question "UVa 00348 - Optimal Array Multiplication Sequence"
    承接矩陣相乘問題，需要輸出優先相乘順序，用括號表示。

在轉移過程中多維護一個陣列 $to$ 紀錄每個區間的最佳分割點，輸出的時候根據 $to$ 的結果遞迴輸出答案。

??? "參考程式碼"
    ```cpp
    --8<-- "docs/dynamicProgramming/code/uva00348.cpp"
    ```

???+ Question "最佳二元搜尋樹"
    給定 $N$ 個元素的搜尋頻率(機率) $F_i$，假設元素在二元搜尋樹的深度 $d_i$，請找出一顆二元搜尋樹讓 $cost=\Sigma F_id_i$ 最小。

- 和霍夫曼樹的差異：元素的相對位置是固定的，沒辦法移動。
- 狀態：$f(i,j)=$ 由第 $i$ 個元素到第 $j$ 個元素形成的(子)樹最小 cost。
- 初始狀態：$f(i,i)=F_i$
- 轉移式子：$f(i,j)=\Sigma_{x=i}^{j}f_x+min\{f(i,k-1)+f(k+1,j)|i<=k<=j\}$
    - 枚舉子樹的根，遞迴計算左右子樹的 $cost$

## 例題練習

- UVa 10559
- UVa 1351
- UVa 1626
- UVa 1630
- AtCoder Educational DP Contest - N
- AtCoder Educational DP Contest - L