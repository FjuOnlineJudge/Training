#  `cctype` 函式庫

 `cctype` 函式庫是 `C` 的函式庫，主要是用來判斷字元種類和轉換字元，以下敘述為競賽常用的函式：

???+ 引入

    - `C`: `ctype.h`
    - `C++`: `cctype`

-  `isalnum` : 判斷是否為數字或英文。
-  `isalnum(int c)` 
-  `isalpha` : 判斷是否為英文。
-  `isalpha(int c)` 
-  `isdigit` : 判斷是否為數字。
-  `isdigit(int c)` 
-  `islower` : 判斷是否為小寫字母。
-  `islower(int c)` 
-  `isupper` : 判斷是否為大寫字母。
-  `isupper(int c)` 
-  `tolower` : 將字母轉乘小寫字母
-  `islower(int c)` 
-  `toupper` : 將字母轉乘大寫字母
-  `toupper(int c)` 

## 實例

- 將所有英文字母轉成小寫字母後輸出

```cpp
char str[] = "Cats Like Chatching The Mouses.";
for (int i = 0; i != (int)strlen(str); ++i) {
  if (isalpha(str[i])) {
    str[i] = tolower(str[i]);
  }
}
printf("%s\n", str);

/*
cats like chatching the mouses.
*/
```

[^1]:  [cctype 函式庫 in cplusplus](http://www.cplusplus.com/reference/cctype/) 
