存好圖後，為了獲得某些資訊，需要遍歷或搜索圖。以下介紹兩種方法：DFS和BFS。

## 深度優先搜尋 (Depth First Search, DFS)
DFS 會優先搜尋距離起點遠的，通常用遞迴實作或用 `stack` 維護。

```cpp
vector<int>G[N];
bitset<N> vis;
void dfs(int s){
    vis[s]=1;
    for(int t:G[s]){
        if(!vis[i])dfs(i);
    }
}
```

## 廣度優先搜尋 (Breadth First Search, BFS)
BFS 會把距離起點相同的點遍歷過後，再去遍歷距離更遠的點。通常以queue來維護。
```cpp
vector<int>G[N];
bitset<N> vis;
void bfs(int s){
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int v=q.front(); q.pop();
        for(int t:G[v]){
            if(!vis[t]){
                q.push(t);
                vis[t]=1;
            }
        }
    }
}
```