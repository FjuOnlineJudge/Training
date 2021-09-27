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
int main() {
  printf("Min(1,2): %d\n", min(1, 2));
  printf("max(1,2): %d\n", max(1, 2));
  printf("Min({2,7,5}): %d\n", min({2, 7, 5}));
  printf("max({2,7,5}): %d\n", max({2, 7, 5}));
  vector<int> a = {4, 6, 9, 3};
  printf("Min_element(a): %d\n", *min_element(a.begin(), a.end()));
  printf("max_element(a): %d\n", *max_element(a.begin(), a.end()));
}

/*
Min(1,2): 1
max(1,2): 2
Min({2,7,5}): 2
max({2,7,5}): 7
Min_element(a): 3
max_element(a): 9
*/
```

- 排序元素

```cpp
int cmp(int a, int b) { return a > b; }

int main() {
  int arr[5] = {2, 9, 6, 5, 7};
  printf("Before sorting:\n");
  for (int i = 0; i < 5; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  sort(arr, arr + 5);
  printf("After sorting:\n");
  for (int i = 0; i < 5; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  sort(arr, arr + 5, cmp);
  printf("After sorting with user-defined function:\n");
  for (int i = 0; i < 5; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/*
Before sorting:
2 9 6 5 7
After sorting:
2 5 6 7 9
After sorting with user-defined function:
9 7 6 5 2
*/
```

- 尋找元素

```cpp
int main() {
  vector<int> a = {4, 6, 9, 3};
  for (int i = 0; i < 5; ++i) {
    if (find(a.begin(), a.end(), i) != a.end()) {
      printf("%d is find at %d\n", i,
             (int)(find(a.begin(), a.end(), i) - a.begin()));
    }
  }
  sort(a.begin(), a.end());
  printf("The lower_bound of %d is at %d\n", 5,
         (int)(lower_bound(a.begin(), a.end(), 5) - a.begin()));
  printf("The upper_bound of %d is at %d\n", 5,
         (int)(upper_bound(a.begin(), a.end(), 5) - a.begin()));
}

/*
3 is find at 3
4 is find at 0
The lower_bound of 5 is at 2
The upper_bound of 5 is at 2
*/
```

- 下（上）一個字典序

```cpp
int main() {
  vector<int> a1 = {4, 2, 7, 5};
  vector<int> a2(a1);
  if (next_permutation(a1.begin(), a1.end())) {
    for (int i = 0; i < (int)a1.size(); ++i) {
      printf("%d%c", a1[i], " \n"[i == (int)a1.size() - 1]);
    }
  }
  if (prev_permutation(a2.begin(), a2.end())) {
    for (int i = 0; i < (int)a2.size(); ++i) {
      printf("%d%c", a2[i], " \n"[i == (int)a2.size() - 1]);
    }
  }
}

/*
4 5 2 7
4 2 5 7
*/
```

[^1]:  [algoruthm 函式庫 in cplusplus](https://cplusplus.com/reference/algorithm/) 
