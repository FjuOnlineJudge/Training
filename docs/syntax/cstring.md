#  `cstring` 函式庫

 `cstring` 函式庫是 `C` 的函式庫，定義操作陣列的函式庫，以下敘述為競賽常用的函式：

???+ 引入

    - `C`: `string.h`
    - `C++`: `cstring`

-  `memcpy` : 從 `source` 複製 `num` bytes 記憶體到 `destination` 。

-  `memcpy (destination, source, num)` 

-  `strcpy` : 從 `source` 複製 C 式字串到 `destination` 。

-  `strcpy(destination, source)` 

-  `strncpy` : 從 `source` 複製 `num` 個字元記憶體到 `destination` 。

-  `strncpy(destination, source, num)` 

-  `srtcat` : 將 `source` 接到 `destination` 後面。

-  `strcat(destination, source)` 

-  `strncat` : 將 `source` 的前 `num` 個字元接到 `destination` 後面。

-  `strncat(destination, source, num)` 

-  `memcmp` : 比較兩記憶體前 `num` bytes。

-  `memcmp(ptr1, ptr2, num)` 

-  `strcmp` : 比較兩字串。

-  `strcmp(str1, str2)` 

???+ "比較函數結果"

| 結果    | 說明       |
| ----- | -------- |
| &lt;0 | 前者&lt;後者 |
| =0    | 前者 = 後者  |
| >0    | 前者 > 後者  |

-  `memset` : 設定 `ptr` 前 `num` bytes 為 `value` 

-  `memset(ptr, value, num)` 

-  `memset` 應該是要設定字元，然而整數型態的 $0$ 和 $-1$ ，的每個 bytes 剛好也是 $0$ 和 $-1$ ，所以 `memset` 也可用來設定整數陣列全為 $0$ 和 $-1$ 。

-  `srtlen` : 回傳 C 式字串的長度

-  `strlen(str)` 

## 範例

- 複製字串

```cpp
--8<-- "docs/syntax/code/cstring1.cpp"
```

- 串接字串

```cpp
--8<-- "docs/syntax/code/cstring2.cpp"
```

- 比較字串大小（字典序）

```cpp
--8<-- "docs/syntax/code/cstring3.cpp"
```

- 設定字元陣列

```cpp
--8<-- "docs/syntax/code/cstring4.cpp"
```

- 設定整數陣列

```cpp
--8<-- "docs/syntax/code/cstring5.cpp"
```

[^1]:  [cstring 函式庫 in cplusplus](http://www.cplusplus.com/reference/cstring/) 
