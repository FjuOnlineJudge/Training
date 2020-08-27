# List
陣列如果要從中間插入一個元素，需要將其後面所有元素搬移一格，需耗費$O(n)$，連結串列(`linklist`)能只花$O(1)$完成插入。
```cpp
struct Node{
    int v;
    Node *next=nullptr;
};
```
```cpp
struct Node{
    int v;
    Node *next=nullptr,*prev=nullptr;
};
```
可以利用陣列取代指標來實作 `linklist`。
C++提供list函式庫實作雙向串列。
* 標頭檔：`<list>`
* 建構式：`list <T> L`
* `L.size()`：回傳元素個數，複雜度$O(1)$
* `L.empty()`：回傳是否為空，複雜度$O(1)$
* `L.push_front(T a),L.push_back(T a)`：插入頂端/尾端元素，複雜度$O(1)$
* `L.pop_front(),L.pop_back()`：刪除頂端/尾端元素，複雜度$O(1)$
* `L.insert(iterator it,size_type n,T a)`：在 it 指的那項的前面插入 n 個 a 並回傳指向 a 的迭代器。複雜度 $O(n)$。
* `L.erase(iterator first,iterator last)`：把 $[first,last)$ 指到的東西全部刪掉,回傳 last。複雜度與砍掉的數量呈線性關係,如果沒有指定 last,那會自動視為只刪除 first 那項。
* `L.splice(iterator it,list &x,iterator first,iterator last)`：first 和 last 是 x 的迭代器。此函式會把 $[first,last)$ 指到的東西從 x 中剪下並加到 it 所指的那項的前面。x 會因為這項函式而改變。若未指定 last,那只會將 first 所指的東西移到 it 前方。複雜度與轉移個數呈線性關係。
```cpp
// adapt from cppreference
#include <iostream>
#include <list>
 
int main(){
    std::list<char> letters {'o', 'm', 'g', 'w', 't', 'f'};
 
    if (!letters.empty()) {
        cout << letters.front() << '\n';// o
        cout << letters.back() << '\n'; // f
    }  
}
```