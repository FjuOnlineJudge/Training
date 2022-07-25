# Codebook 準備

這裡提供常見放到 Codebook 的主題，每支隊伍依據程度選擇放不同的程式碼，程式碼取捨原則如下：

- 不知道要怎麼用的程式碼優先度最低
- 難記的程式碼優先度比好記的的程式碼高
- 常見的程式碼優先度高

## 模板

模板在開局的時候由一位隊員撰寫，之後每題題目先複製一份模板再使用，模板裡會放一些常見的縮寫，通常用 `define`, `using` 定義。

使用 vimrc 可以放入 `.vimrc`，還可以放編譯的執行的腳本。

## 基礎

- 各種輸入、輸出
    - `getline`
    - `stringstream`
- `algorithm` 函式庫
    - `sort`
    - `next_permutation`,`prev_permutation`
    - Binary search 相關

```cpp
lower_bound(a, a + n, k);     //最左邊 ≥ k 的位置
upper_bound(a, a + n, k);     //最左邊 > k 的位置
upper_bound(a, a + n, k) - 1; //最右邊 ≤ k 的位置
lower_bound(a, a + n, k) - 1; //最右邊 < k 的位置
[lower_bound, upper_bound) //等於 k 的範圍
equal_range(a, a+n, k);
```

## STL 

- `priority_queue`
- `map`
- `set`
- `vector`
- `string`


## 圖論

- 並查集
- 最小生成樹
- 最短路
    - Floyd-Warshall
    - Bellman-Ford
    - SPFA
    - Dijkstra’s
- 最低共同祖先
- 連通性
    - Tarjan
    - Kosaraju's
- 歐拉迴路

### 二分圖和流

- 二分圖判定
- 二分圖最大匹配
- 二分圖最大權重匹配
- Dinic 最大流演算法
- 費用流演算法

## 數學
- 質因數分解
- 歐拉定理 $\phi(N)$
- 擴展歐基里德演算法
- 快速冪
- 中國剩餘定理
- 一些數學定理

## Python
- 一些用有的函式(要確定內建)
- eof 寫法
- eval
