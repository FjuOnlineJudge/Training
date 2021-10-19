#  `algorithm` 函式庫

 `C++` 的 `algorithm` 函式庫提供常用的操作，尤其是區間（序列的一段範圍）操作，包含最大最小值，排序。

???+ 引入
     `C++` : `algorithm` 

-  `min` ：取最小值。
-  `min(a, b)` 
-  `min(list)` 
-  `max` ：取最大值。
-  `max(a, b)` 
-  `max(list)` 


-  `min_element` ：找尋最小元素
-  `min_element(first, last)` 
-  `max_element` ：找尋最大元素
-  `max_element(first, last)` 


-  `sort` ：排序，預設由小排到大。
-  `sort(first, last)` 
-  `sort(first, last, comp)` ：可自行定義比較運算子 `Comp` 。
-  `find` ：尋找元素。
-  `find(first, last, val)` 
-  `lower_bound` ：尋找第一個 $\gq x$ 的元素位置，如果不存在，則回傳 `last` 。
-  `lower_bound(first, last, val)` 
-  `upper_bound` ：尋找第一個 $> x$ 的元素位置，如果不存在，則回傳 `last` 。
-  `upper_bound(first, last, val)` 
-  `next_permutation` ：將序列順序轉換成下一個字典序，如果存在回傳 `true` ，反之回傳 `false` 。
-  `next_permutation(first, last)` 
-  `prev_permutation` ：將序列順序轉換成上一個字典序，如果存在回傳 `true` ，反之回傳 `false` 。
-  `prev_permutation(first, last)` 

## 範例

- 最小（大）值

```cpp
--8<-- "docs/syntax/code/algorithm1.cpp"
```

- 排序元素

```cpp
--8<-- "docs/syntax/code/algorithm2.cpp"
```

- 尋找元素

```cpp
--8<-- "docs/syntax/code/algorithm3.cpp"
```

- 下（上）一個字典序

```cpp
--8<-- "docs/syntax/code/algorithm4.cpp"
```

[^1]:  [algoruthm 函式庫 in cplusplus](https://cplusplus.com/reference/algorithm/) 
