# Heap
維護最大/小值，可插入、刪除、及詢問最大/小值，一種實作為binary heap
```cpp
int heap[N],top=0;
void push(int v){
    heap[++top]=v;
    for(int i=top;i>1;){
        if(heap[i]<=heap[i/2])break;
        swap(heap[i],heap[i/2]);
        i<<=1;
    }
}
void pop(){
    heap[1]=heap[top--];
    for(int i=1;(i<<1)<=top;){
        if(heap[i]<heap[i<<1]){
            swap(heap[i],heap[i<<1]);
            i<<=1;
        }else if((i<<1)<top&&heap[i]<heap[(i<<1)+1]){
            swap(heap[i],heap[(i<<1)+1]);
            i=(i<<1)+1;
        }else{
            break;
        }
    }
}
```
C++ 的 `priorty_queue` (優先隊列)，是一種 Heap 的實作。
* 標頭檔：`<queue>`
* 建構式：`priorty_queue <T> pq`
* 建構式：`priorty_queue <T,Con,Cmp> pq`
* 建構式：`priorty_queue <T,Con,Cmp> pq(iterator first, iterator seecond)` 插入 $[first,second)$ 內的東西
* `pq.push(T a)`：插入元素 $a$，複雜度 $O(\log size)$
* `pq.pop()`：刪除頂端元素，複雜度 $O(\log size)$
* `pq.top()`：回傳頂端元素，複雜度 $O(1)$
* `pq.size()`：回傳元素個數，複雜度 $O(1)$
* `pq.empty()`：回傳是否為空，複雜度 $O(1)$
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int>Q;
    Q.push(2);
    cout<<Q.top()<<'\n';// 2
    Q.push(5);
    cout<<Q.top()<<'\n';// 5
    Q.pop();
    cout<<Q.top()<<'\n';// 2
    Q.push(3);
    cout<<Q.top()<<'\n';// 3
}
```