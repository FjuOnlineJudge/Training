# 函式與遞迴

函式為程式裡的運算單元，可以接受資料，並回傳指定值。main 是 C/C++ 程式的入口函式，接受命令列的參數，正常情況會回傳 0 代表正常運作。
以下為其語法

```cpp
return_type function_name(parameter list) {
  Do something... return data; // void need not return;
}
```

範例

```cpp
int sum(int x, int y) {
  int sum = 0;
  sum += x;
  sum += y;
  reutnr x + y;
}
```

函式有個特性為自呼叫，也就是自己的區域可以呼叫自己，但要有終止條件，不然會陷入無限遞迴，同時也要避免遞迴過深，造成 stack overflow。

```cpp
int ans;
void f(int i) {
  if (i == 1) {
    ans = 1;
    return;
  }
  f(i - 1);
  ans *= i;
  return;
}
```

函式有很多用處，一個為模組化，意即相同的部分（最多只差一些參數），寫成一個函式，除了簡潔，在除錯也比較方便。一個是利用自呼叫特性實作遞迴，遞迴可將問題拆解成同類的子問題而解決問題。

-   常見遞迴使用
    - 分治
    - dp 中的 top-down
    - 圖/樹的搜索
