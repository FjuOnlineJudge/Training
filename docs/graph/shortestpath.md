# 最短路徑

## 術語

- 負邊：權重為負的邊
- 負環：權重和為負的環
- 點源：成為起點的點，分成單源頭及多源頭。
- 鬆弛：單源頭最短路徑中，對於任意兩個點 $u,v$ ，起點 $s$ 到它們的距離 $d_u,d_v$ ，如果 $d_u>d_v+w_{u,v}$ ， $w_{u,v}$ 為邊 $(u,v)$ 的權重，我們可以讓 $d_u$ 更新為 $d_v+w_{u,v}$ ，讓 $s$ 到 $u$ 的距離縮短，這個動作稱為 "鬆弛"。

## Floyd-Warshall Algorithm

為多源頭最短路徑，求出所有點對的最短路徑。
Floyd-Warshall 是一種動態規劃問題，以下是他的 dp 式。

- 狀態： $dp[k][i][j]$ 代表，若只以點 $1 ∼ k$ 當中繼點的話，則 $dp[k][i][j]$ 為 $i$ 到 $j$ 的最短路徑長。
- 轉移： $dp[k][i][j] = min(dp[k − 1][i][k] + dp[k − 1][k][j], dp[k − 1][i][j])$ 
-   基底：
    $$
    dp[0][i][j] = \left\{ \begin{array}{cc}w[i][j] & if\ w[i][j]\ exists\\INF & else\end{array} \right\}
    $$

時/空間複雜度皆為 $O(V^3)$ ，然而此 DP 是可以滾動，所以空間複雜度可降為 $O(V^2)$ 

```cpp
for (k = 0; k < n; k++)
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      w[i][j] = w[j][i] = min(w[i][j], max(w[i][k], w[k][j]));
```

執行的時候如果 $dp[i][j]\leq 0$ ，代表存在負環，Floyd-Warshall 是可以判斷負環。

## 單點源最短路徑

求出一個點到所有點的最短路徑，其實就是以起點為根，最短路徑是由父節點鬆弛而來的最短路徑樹。我們找最短路徑，就是一直把鬆弛，直到所有點都不能鬆弛，所有點都獲得最短路徑了。要蓋出最短路徑樹，就只要把點指向最後一次被誰鬆弛就好了。

## Bellman-Ford Algorithm

為單點源最短路徑，設起點的最短路徑為 0，其他點為無限大，每次對所有邊枚舉，因為最短路徑不會經過同樣的邊第二次，所以只要執行 $V-1$ 輪，複雜度為 $O(VE)$ 。如果執行第 $V$ 次時還有邊可以鬆弛，代表有負環，Bellman-Ford 也可以當成負環的判斷方法。

```cpp
void bellman_ford(int s) {
  d[s] = 0;
  p[s] = s;
  for (int i = 0; i < V - 1; i++) {
    for (int ss = 0; ss < V; ss++) {
      for (auto tt : v[ss]) {
        if (d[ss] + w[ss][tt] < d[tt]) {
          d[tt] = d[ss] + w[ss][tt];
          p[tt] = ss;
        }
      }
    }
  }
}
bool has_negative_cycle() {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (d[i] + w[i][j] < d[j])
        return true;
    }
  }
  return false;
}
```

此演算法還有一個優化版本叫做 Shortest Path Faster Algorithm (SPFA)，他的做法是枚舉起點是鬆弛過的邊，以鬆弛過的點除非被重新鬆弛，否則不會更動。預期複雜度為 $O(V+E)$ ，不過最差狀況仍為 $O(VE)$ 。

## Dijkstra’s Algorithm

同樣為單點源最短路徑，他的想法和 Prim's Algorithm 類似，每次把離樹根最近的點加入最短路徑樹裡，並把所有與該點相連的邊鬆弛，已經加入的點不會在被鬆弛。使用 `priority_queue` 的複雜度為 $O((V+E)\log E)$ ，使用費波那契堆，複雜度為 $O(E+V\log V)$ 

```cpp
struct edge {
  int s, t;
  LL d;
  edge(){};
  edge(int s, int t, LL d) : s(s), t(t), d(d) {}
};

struct heap {
  LL d;
  int p; // point
  heap(){};
  heap(LL d, int p) : d(d), p(p) {}
  bool operator<(const heap &b) const { return d > b.d; }
};
int d[N], p[N];
vector<edge> edges;
vector<int> G[N];
bitset<N> vis;
void dijkstra(int ss) {
  priority_queue<heap> Q;
  for (int i = 0; i < V; i++)
    d[i] = INF;
  d[ss] = 0;
  p[ss] = -1;
  vis.reset() : Q.push(heap(0, ss));
  heap x;
  while (!Q.empty()) {
    x = Q.top();
    Q.pop();
    int p = x.p;
    if (vis[p])
      continue;
    vis[p] = 1;
    for (int i = 0; i < G[p].size(); i++) {
      edge &e = edges[G[p][i]];
      if (d[e.t] > d[p] + e.d) {
        d[e.t] = d[p] + e.d;
        p[e.t] = G[p][i];
        Q.push(heap(d[e.t], e.t));
      }
    }
  }
}
```

而 Dijkstra’s Algorithm 不能處理負邊，原因是一旦點加入最短路徑樹，就不會再被更新，以維持良好複雜度，負邊會破壞此規則。
