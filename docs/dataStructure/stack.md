# stack 堆疊

有兩個端口，其中一個封閉，另一個端口負責插入、刪除的資料結構

![](images/stack.gif)

```cpp
--8<-- "docs/dataStructure/code/stack1.cpp"
```

- 標頭檔： `<stack>` 
- 建構式： `stack <T> s` 
-  `s.push(T a)` ：插入頂端元素，複雜度 $O(1)$ 
-  `s.pop()` ：刪除頂端元素，複雜度 $O(1)$ 
-  `s.top()` ：回傳頂端元素，複雜度 $O(1)$ 
-  `s.size()` ：回傳元素個數，複雜度 $O(1)$ 
-  `s.empty()` ：回傳是否為空，複雜度 $O(1)$ 

```cpp
--8<-- "docs/dataStructure/code/stack2.cpp"
```
