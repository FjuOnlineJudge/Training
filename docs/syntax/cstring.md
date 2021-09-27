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
char str1[] = "This is an apple.";
char str2[] = "That is a banana.";
printf("Before strcpy:\n");
printf("%s\n", str2);
strcpy(str2, str1);
printf("\nAfter strcpy:\n");
printf("%s\n", str2);

/*
Before strcpy:
That is a banana.

After strcpy:
This is an apple.

*/
```

- 串接字串

```cpp
char str[] = "Ha!";
printf("Before strcpy:\n");
printf("%s\n", str);
strcat(str, " Hello!");
printf("\nAfter strcpy:\n");
printf("%s\n", str);

/*
Before strcpy:
Ha!

After strcpy:
Ha! Hello!

*/
```

- 比較字串大小（字典序）

```cpp
char str1[] = "This is an apple.";
char str2[] = "That is a banana.";
int res = memcmp(str1, str2, sizeof(str1));
if (res > 0) {
  printf("'%s' is greater than '%s'.\n", str1, str2);
} else if (res < 0) {
  printf("'%s' is less than '%s'.\n", str1, str2);
} else {
  printf("'%s' is the same as '%s'.\n", str1, str2);
}

/*
'This is an apple.' is greater than 'That is a banana.'.

*/
```

- 設定字元陣列

```cpp
char str[5];
printf("Before memeset:\n");
for (int i = 0; i < (int)strlen(str); ++i) {
  printf("%c", str[i]);
}
memset(str, '+', sizeof(str));
printf("\nAfter memeset:\n");
for (int i = 0; i < (int)strlen(str); ++i) {
  printf("%c", str[i]);
}

/*
Before memeset:

After memeset:
+++++
*/
```

- 設定整數陣列

```cpp
int arr[5];
printf("Before memeset:\n");
for (int i = 0; i < 5; ++i) {
  printf("%d ", arr[i]);
}
memset(arr, -1, sizeof(arr));
printf("\nAfter memeset:\n");
for (int i = 0; i < 5; ++i) {
  printf("%d ", arr[i]);
}

/*
Before memeset:
8 0 2 0 7480496
After memeset:
-1 -1 -1 -1 -1
*/
```

[^1]:  [cstring 函式庫 in cplusplus](http://www.cplusplus.com/reference/cstring/) 
