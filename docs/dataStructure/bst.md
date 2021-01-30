# 二元平衡樹

set 和 map 皆為二元平衡樹，支援插入、刪除及查詢一個值，不同的是，set 會回傳鍵值，map 則是回傳對應值，也可以說 set 的鍵值和對應值一樣

## set

- 標頭檔： `<set>` 
- 建構式： `set <T1> s` 
-  `s.size()` ：回傳元素個數，複雜度 $O(1)$ 
-  `s.empty()` ：回傳是否為空，複雜度 $O(1)$ 
-  `s.clear()` ：清除元素，複雜度 $O(size)$ 
-  `s.insert(T1 a)` ：加入元素 a, 複雜度 $O(\log size)$ 。
-  `s.erase(iterator first,iterator last)` ：刪除 $[first,last)$ , 若沒有指定 last 則只刪除 first, 複雜度 $O(\log size)$ 與加上元素個數有關係。
-  `s.erase(T1 a)` ：刪除鍵值 a, 複雜度 $O(\log size)$ 。
-  `s.find(T1 a)` ：回傳指向鍵值 a 的迭代器，若不存在則回傳 s.end (), 複雜度 $O(\log size)$ 。
-  `s.lower_bound(T1 a)` ：回傳指向第一個鍵值大於等於 a 的迭代器。複雜度 $O(\log size)$ 。
-  `s.upper_bound(T1 a)` ：回傳指向第一個鍵值大於 a 的迭代器。複雜度 $O(\log size)$ 。

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> sb;
  sb.insert(1);
  sb.insert(2);
  sb.insert(3);

  cout << "1 : " << (sb.find(1) != sb.end() ? "find\n" : "not find\n");
  cout << "1 : " << (sb.count(1) ? "find\n" : "not find\n");

  sb.erase(1);
  cout << "1 : " << (sb.find(1) != sb.end() ? "find\n" : "not find\n");
  cout << "1 : " << (sb.count(1) ? "find\n" : "not find\n");
}
```

    1 : find
    1 : find
    1 : not find
    1 : not find

## map

- 標頭檔： `<map>` 
- 建構式： `map <T1, T2> m` 
-  `m.size(),m.empty(),m.clear(),m.erase(iterator first,iterator last),m.erase(T1 a),m.find(T1 a),m.lower_bound(T1 a),m.upper_bound(T1 a)` ：同 set。
-  `m[a]` ：存取鍵值 a 對應的值，若 a 沒有對應的值，會插入一個元素，使 a 對應到預設值並回傳之。複雜度 $O(\log size)$ 。
-  `m.insert(pair<T1,T2> a)` ：若沒有鍵值為 a.first 的值，插入一個鍵值為 a.first 的值對應到 a.second, 並回傳一個 pair,first 是指向剛插入的元素的迭代器、second 是 true; 若已經有了，回傳一個 pair,first 是指向鍵值為 k.first 的元素的迭代器，second 是 false。複雜度 $O(\log size)$ 。

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
  map<string, int> tb;
  tb["123"] = 1;
  tb["owowowo"] = 2;
  tb["omomo"] = 3;
  cout << "tb[\"123\"]: " << tb["123"] << '\n';
  cout << "tb[\"owowowo\"]: " << tb["owowowo"] << '\n';
  cout << "tb[\"omomo\"]: " << tb["omomo"] << '\n';

  cout << "123 : " << (tb.find("123") != tb.end() ? "find\n" : "not find\n");
  cout << "123 : " << (tb.count("123") ? "find\n" : "not find\n");

  tb.clear();
  cout << "123 : " << (tb.find("123") != tb.end() ? "find\n" : "not find\n");
  cout << "123 : " << (tb.count("123") ? "find\n" : "not find\n");

  cout << "owo : " << (tb.find("owo") != tb.end() ? "find\n" : "not find\n");
  tb.insert(make_pair("owo", 659));
  cout << "owo : " << (tb.find("owo") != tb.end() ? "find\n" : "not find\n");
}
```

    tb["123"]: 1
    tb["owowowo"]: 2
    tb["omomo"]: 3
    123 : find
    123 : find
    123 : not find
    123 : not find
    owo : not find
    owo : find

## multi - 系列

可插入重複元素，代價為 map 無法用下標運算子

- equal_range (T1 a)：回傳 iterator 的 `pair<lower_bound (a),upper_bound (a)>` ，為 a 所在範圍
- erase (T1 a)：刪除所有元素 a，如果只要刪除一個，用 `s.erase (s.find (a))` 

## unorder - 系列

降低常數，期望複雜度少一個 log，代價為不會排序，沒有 `lower_bound/upper_bound` ，也不會依鍵值大小遍歷。迭代器為單向。
