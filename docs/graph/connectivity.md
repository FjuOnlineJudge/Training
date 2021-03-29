# 連通性 (Connectivity)

一張任意兩點接連通的圖叫做連通圖，在實際情況，例如網路或電力的架設都希望線路是連通的，要是地方壞掉，我們希望影響能越小越好。在圖論中，有算法可以找出去掉那些部分會使得圖變成不連通的，以下詳細說明。

## DFS 邊分類

根據 DFS 的順序（時間戳記），對邊進行分類，這些分類在之後的章節會用到。

| 名稱                 | 指向     | 無向圖 | 有向圖 |
| ------------------ | ------ | --- | --- |
| 樹邊 (Tree edge)     | 兒子     | 有   | 有   |
| 回邊 (Back edge)     | 祖先     | 有   | 有   |
| 前向邊 (Forward edge) | 非兒子的子孫 | 無   | 有   |
| 交錯邊 (Cross edge)   | 旁系血親   | 無   | 有   |

## 無向圖的雙連通

- 點連通度：最少要移除多少個點才會讓整張圖不再連通
- 邊連通度：最少要移除多少條邊才會讓整張圖不再連通
- 雙連通：移除任意一個 "x" 後，圖依然是連通的，就稱為 "x - 雙連通"。依照 "x" 的不同，可分為 "點雙連通" 及 "邊雙連通"。

在之前提到的例子，網路的架設，需要特別注意雙連通的問題，萬一有部分的線路（邊）或是設備（點）損壞，就有可能導致一部分的網路不連通。以下分別從點和邊的角度探討雙連通。

## Tarjan 算法：找 $low$ 函數

Tarjan 算法，可解決許多連通性的問題，最核心的是找出每個點 $low$ 函數。

-  $depth[u]$ : 點 $u$ 的深度。
-  $low[u]$ : $u$ 在不經過父親連到自己的 Tree Edge 的情況下，所能到達祖先的最低深度。

在無向圖中，只會遇到 Tree Edge 和 Back Edge，以下針對兩種情況說明：

- Edge $u\to v$ is a tree edge: $v$ 是 $u$ 的兒子， $u$ 可能經由 $v$ 走到其他祖先，遞迴找尋 $low[v]$ ，再更新 $low[v]=min(low[u],low[v])$ 。
- Edge $u\to v$ is a back edge: $v$ 是 $u$ 的祖先，更新 $low[v]=min(low[u],depth[v])$ 。

```cpp
int low[MXV], depth[MXV];
bool visit[MXV];
vector<int> G[MXV];

void dfs(int now, int cur_depth) {
  visit[now] = true;
  depth[now] = low[now] = cur_depth;
  for (auto i : G[now]) {
    if (visit[i]) { // ancestor
      low[now] = min(low[now], depth[i]);
    } else { // offspring
      dfs(i, cur_depth + 1);
      low[now] = min(low[now], low[i]);
    }
  }
  return;
}
```

## 點雙連通：找割點

要判斷一張圖是否點雙連通，就要檢查他是否有割點，如果沒有割點，則這張圖為點雙連通。

割點：給定一張圖 $G$ ，如果移除點 $v$ 及連接 $v$ 的邊之後，圖 $G$ 不再連通，點 $v$ 都被稱為 $G$ 的一個割點（cut-vertex）或關節點（articulation-vertex, articulation-point)。

根據 $low$ 函數，以下兩種情況能判斷一個點為割點：

- 非根結點 $u$ ：存在一個孩子 $v, low[v]\leq depth[u]$ 。
- 根節點 $root$ ：擁有 $\geq$ 兩個兒子。

```cpp
int low[MXV], depth[MXV];
bool is_cut_vertex[MXV], visit[MXV];
vector<int> G[MXV];

void dfs(int now, int cur_depth) {
  visit[now] = true;
  depth[now] = low[now] = cur_depth;
  int cut_son = 0;
  for (auto i : G[now]) {
    if (visit[i]) { // ancestor
      low[now] = min(low[now], depth[i]);
    } else { // offspring
      dfs(i, cur_depth + 1);
      cut_son += 1;
      low[now] = min(low[now], low[i]);
      if (low[i] >= depth[now])
        is_cut_vertex[now] = true;
    }
  }
  if (cur_depth == 0)
    is_cut_vertex[now] = (cut_son != 1);
  return;
}
```

這個演算法主要是做 DFS，所以時間複雜度為 $O(V+E)$ 

## 邊雙連通

和點連通相似，要判斷一張圖是否邊雙連通，就要檢查他是否有割邊，如果沒有割邊，則這張圖為邊雙連通。

割邊：給定一張圖 $G$ ，如果移除邊 $e$ 及 $e$ 連接的點之後，圖 $G$ 再連通，邊 $e$ 都被稱為 $G$ 的一個割邊（cut-edge）或橋（bridge)。

樹邊才有可能是橋，其他的邊拔除仍然可以藉由樹邊連通。

根據 $low$ 函數，以下情況能判斷一個點為割邊：

-   樹邊 $u\to v$ ： $low[v] < depth[u]$ 。
    -  $low[v] == depth[u]$ 代表有 $u,v$ 之間存在至少兩條路徑。

```cpp
int low[MXV], depth[MXV];
bool visit[MXV];
vector<int> G[MXV];
vector<pair<int, int>> my_cut_edge;

void dfs(int now, int cur_depth, int parent) {
  visit[now] = true;
  depth[now] = low[now] = cur_depth;
  // int cut_son = 0;
  for (auto i : G[now]) {
    if (i != parent)
      continue;
    if (visit[i]) { // ancestor
      low[now] = min(low[now], depth[i]);
    } else { // offspring
      dfs(i, cur_depth + 1, now);
      // cut_son += 1;
      low[now] = min(low[now], low[i]);
      if (low[i] > depth[now])
        my_cut_edge.push_bach({now, i});
    }
  }
  return;
}

bool is_2_edge_connected(int n) {
  int cut_edge = 0;
  memset(visit, 0, sizeof(visit));
  dfs(1, 0, -1);
  return my_cut_edge.size() == 0;
}
```

和前面點雙連通相同，時間複雜度為 $O(V+E)$ 

???+ "重邊處理"
    如果不處理重邊，有可能讓一條邊從非割邊判成割邊。
    處理方式為用 `set,map` 存邊的兩點編號，當遇到一條往父親的邊 $e$ ，如果出現過相同起始點的邊 $e_1$ ，那麼 $e$ 不是樹邊，可以透過 $e$ 回到父親。

## 雙連通元件

- 連通元件：一張圖 $G$ 有很多子圖，如果一個子圖 $G'$ 是連通的，我們稱之為連通元件（connected component)，如果一個連通元件滿足 "加上任意一個其他的點就不再連通"，則稱這樣的連通元件是 "極大的"(maximal)。
- 邊雙連通元件：如果一張的某個子圖是一張邊雙連通圖，我們就成這張子圖為邊連通元子圖（bi-edge-connected graph）或邊雙連通元件（bi-edge-connected component)。
- 點雙連通元件：如果一張的某個子圖是一張點雙連通圖，我們就成這張子圖為點連通元子圖（bi-vertex-connected graph）或點雙連通元件（bi-vertex-connected component)。

一般來說，我們會討論極大的連通元件，以下所有的連通元件都是極大的。

要一張張圖的所有邊雙連通元件，只要拔掉所有橋，剩下的圖就是原圖所有的邊連通元件。

至於點連通元件就沒那麼簡單了，因為同一個割點有可能同時存在多的點連通元件內，並且點的相鄰邊不一定不同的點連通元件中，所以我們不能直接拔點拔掉來求出點雙連通元件。

至於為什麼會有這樣的差異，是因為一般的圖是以點為主題，邊用來描敘點和點之間的東西。而點連通問題則是以邊為主體，點用來描述邊和邊之間的關係，後者描述的關係不是二元關係，所以讓問題變得複雜。

那我們就以邊的角度來思考點雙連通元件，對於一個點 $p$ ，與父親點 $f$ 之間有條邊 $e_f$ ，與兒子點 $c$ 之間有條邊 $e_c$ ，如果 $low(c)>depth(p)$ （不計算樹邊），則 $e_f$ 和 $e_c$ 不在同一個點連通元件內，反之 $e_f$ 和 $e_c$ 在同一個點雙連通元件內。根據以上性質，我們可以在 DFS 過程中維護一個 `stack` ，紀錄目前經過的邊，當遇到割點時，可以快速找出點雙連通元件。

```cpp
typedef pair<int, int> PII;
int low[MXV], depth[MXV];
bool is_cut_vertex[MXV], visit[MXV];
vector<int> G[MXV];
vector<PII> BCC[MXV];
int bcc_cnt = 0;
stack<PII> st;

void dfs(int now, int cur_depth, int f) {
  visit[now] = true;
  depth[now] = low[now] = cur_depth;
  int cut_son = 0;
  for (auto i : G[now]) {
    if (i == f)
      continue;
    if (visit[i]) { // ancestor
      if (depth[i] < depth[now]) {
        low[now] = min(low[now], depth[i]);
        st.push({now, i});
      }
    } else { // offspring
      st.push({now, i});
      dfs(i, cur_depth + 1, now);
      cut_son += 1;
      low[now] = min(low[now], low[i]);
      if (low[i] >= depth[now]) {
        is_cut_vertex[now] = true;
        auto t = st.top();
        st.pop();
        while (t != make_pair(now, i)) {
          BCC[bcc_cnt].push_back(t);
          t = st.top();
          st.pop();
        }
        BCC[bcc_cnt].push_back(t);
        ++bcc_cnt;
      }
    }
  }
  if (cur_depth == 0)
    is_cut_vertex[now] = (cut_son != 1);
  return;
}
```

這個演算法一樣有做 DFS，並且維護一個 stack，每條邊都會被丟進去一次，因此時間複雜度為 $O(V+E)$ 。

## 有向圖的強連通

談完了無向圖，就來談論有向圖，有向圖的邊具有方向性，因此比無向圖更難達成 "連通" 的性質，於是為了跟無向圖做區分，訂了一個術語 "強連通" 來表示有向圖的連通性。

- 強連通：對於有向圖上的兩點 $A,B$ ，若存在一條路徑從 $A$ 到 $B$ ，以及存在一條路徑從 $B$ 到 $A$ ，則我們稱 $A,B$ 兩點強連通（strongly connected)
- 強連通圖：如果一張有向圖上任意兩點皆強連通，則這張圖為強連通圖（strongly connected graph)
- 強連通元件：如果一張圖中的某個子圖是一張強連通圖，我們稱這個子圖為強連通子圖（strongly connected subgraph)，或是強連通元件（strongly connected component)

強連通為有向圖中很重要的性質，如果將強連通元件各自縮成一點，新圖是一張有向無環圖（Directed Acyclic Graph, DAG)，DAG 有許多強力性質，可以讓圖上的問題變得有解，有些圖論題目一開始會先找出 SCC 來解題。

## 強連通元件

Tarjan 演算法也可以找出強連通元件，不過邏輯會很複雜，所以我們介紹另一種演算法叫做 Kosaraju's algorithm。

Kosaraju's algorithm 基於觀察到的兩件事而成，第一件事為將原圖每條邊都反向，得到的新圖，所有 SCC 的位置依舊相同。第二件事為如果我們用 "正確的" 順序遍歷圖，每次遍歷到的點視為同一個 SCC，那麼是有可能可以找出正確的 SCC 的。
我們分成三種情況來討論那樣才是正確的遍歷順序。

-  $A,B$ 在同一個 SCC 裡：先拜訪誰都可以，反正另外一個點也會被拜訪到
-  $A,B$ 互相都不能走到對方：這種情況也是先拜訪誰都可以，反正毫不相干
-  $A$ 走的到 $B$ ， $B$ 走不到 $A$ （單向通行）：這種情況只能先走 $B$ 再走 $A$ ，否則先走 $A$ 的話， $B$ 會被認為和 $A$ 在同一個 SCC 內

所以只要給出一個順序，對於所有只有 $A$ 走的到 $B$ ， $B$ 走不到 $A$ 的點對 $(A,B)$ 都滿足 $B$ 會比 $B$ 先被走到，這個演算法就行得通了。基於這個道理，Kosaraju's algorithm 就誕生了：

- 將圖上所有邊反向，得到新圖 $G'$ 
- 在圖 $G'$ 上找一個未拜訪過的點 DFS 並且記錄時間戳，DFS 完後，如果還有點未被 DFS，再進行前敘動作。
- 依時間戳的離開戳記對點由大到小排序，所得序列即為所求。再根據這個序列在原圖 $G$ 做 DFS，每次 DFS 到的點形成一個 SCC。

現在來證明這個序列滿足我們的要求：

- 對於圖 G 上任意單向通行的點對 $A\rightarrow B$ ，在 $G'$ 上會變成單向通行的點對 $B\rightarrow A$ 。
- 如果 $A$ 先被拜訪，因為 $A$ 沒辦法做到 $B$ ，所以 $A$ 會先拜訪完畢，因此 $A$ 的離開戳記會小於 $B$ 的離開戳記。
- 如果 $B$ 先被拜訪， $B$ 一定會走到 $A$ ， $A$ 拜訪完畢時， $B$ 一定還沒拜訪完畢，因此 $A$ 的離開戳記依然會小於 $B$ 的離開戳記。
- 得證 $A$ 的離開戳記一定會小於 $B$ 的離開戳記，即 $B$ 在序列中會在 $A$ 前面。

以下是程式碼，此算法會做兩次 $DFS$ ，時間複雜度為 $O(V+E)$ 。。

```cpp
vector<int> G[MXN];
vector<int> rev_G[MXN];
vector<int> leave;
bitset<MXN> visit;
int at_scc[MXN];

void dfs_for_stamp(int now) {
  visit[now] = true;
  for (auto i : rev_G[now]) {
    if (!visit[i]) {
      dfs_for_stamp(i);
    }
  }
  leave.push_back(now);
}

void dfs_for_scc(int now, int cur_scc) {
  visit[now] = true;
  at_scc[now] = cur_scc;
  for (auto i : G[now]) {
    if (!visit[i]) {
      dfs_for_scc(i, cur_scc);
    }
  }
}

int kosaraju(int n) {
  visit.reset();
  leave.clear();
  for (int i = 0; i < n; ++i) {
    if (!visit[i]) {
      dfs_for_stamp(i);
    }
  }
  visit.reset();
  int scc_count = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (!visit[leave[i]]) {
      dfs_for_scc(leave[i], scc_count++);
    }
  }
  return scc_count;
}
```

## 例題

-   割點模板題
    -  [UVa00796 - Critical Links](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=737) 
-   割邊模板題
    -  [UVa00315 - Network](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=251) 
