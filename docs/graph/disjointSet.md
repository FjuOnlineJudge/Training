# 並查集

並查集是一種樹狀結構，他支援兩件事

-   查詢所隸屬集合
-   合併兩個集合

我們把集合轉化成樹，一顆樹代表一個集合，樹根代表集合的老大，查詢隸屬集合就回傳樹根是誰(一個樹餔可能有兩顆樹根吧)，合併的時侯，就把一顆樹的樹根只到另一顆，以下為詳細的描述。

## 初始

一開始的時候，每個點自成一個集合，所以把樹根都設為自己。

```cpp
int Find(int x){
    if(x==p[x])return x;
    return find(p[x]);
}
```

狀態壓縮：在合併之後原本被指向的樹根就沒用了，我們可以一邊做查詢時，一邊做更新。

```cpp
int Find(int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
}
```

## 查詢

查詢的時候，要查到樹根為自己的點，為止否則的話就要繼續查。

```cpp
void Union(int a,int b){
    a=Find(a); b=Find(b);
    if(a==b)return;
    p[a]=b;
}
```

啟發式合併：建立一個 $h[i]$ 代表樹的高度，亦是元素最大遞迴次數，$h[i]$ 一開始為 $1$。再來，我們每次都讓高度小的高度大的合併，如果遇到高度一樣的，就讓合併別人的樹高度加 $1$。如果要把高度變為 $x$，則至少需要 $2^x$ 個點，由此推出N個點所形成最高之高度為 $\\log(N)$。

```cpp
void Union(int a,int b){
    a=Find(a); b=Find(b);
    if(a==b)return;
    if(rank[a]<rank[b])p[a]=b;
    else if(rank[a]>rank[b])p[b]=a;
    else {p[a]=b; rank[a]++;}
}
```

## 完整程式碼

```cpp
int p[N],rank[N];
void init(){
    for(int i=0;i<N;i++){
        p[i]=i;
        rnak[i]=1;
    }
}
int Find(int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
}
void Union(int a,int b){
    a=Find(a); b=Find(b);
    if(a==b)return;
    if(rank[a]<rank[b])p[a]=b;
    else if(rank[a]>rank[b])p[b]=a;
    else {p[a]=b; rank[a]++;}
}
```
