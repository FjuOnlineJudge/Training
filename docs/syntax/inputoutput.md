# 標準輸入輸出

## 標準輸入輸出、文件輸入輸出

標準輸入：由鍵盤輸入。
標準輸出：輸出到螢幕。
文件輸入：由文件輸入。
文件輸出：輸出到文件。
標準/文件輸出輸入可以混用。

## C 標準輸入輸出

`scanf` 和 `printf` 定義在標頭檔 `stdio.h` 。

`scanf` 和 `printf` 會給定一個由格式碼的字串，並根據格式碼，在後面接上相對應個數的參數。

### `scanf`

`scanf` 的格式碼格式為： `%[*][width][length]specifier`
- `*` 可以指定讀入的資料被忽略。
- `width` 設定最大可輸入字元的個數，請參考 [C 式字串章節](./cstylestring)。
- `length` 設定輸入型態大小，和格式碼搭配。
- `specifier` 為格式碼，是用來指定輸入的型態。

| 常見格式碼  | 說明                     |
| ---- | ---------------------- |
| d   | signed decimal                    |
| u   | unsigned decimal           |
| f   | float                  |
| c   | character                  |


|        | 格式碼     |                         |                |            |        |              |
| ------ | -------------- | ----------------------- | -------------- | ---------- | ------ | ------------ |
| length | d i            | u o x                   | f e g a        | c s [] [^] | p      | n            |
| (none) | int*           | unsigned int*           | float*         | char*      | void** | int*         |
| hh     | signed char*   | unsigned char*          |                |            |        | signed char* |
| h      | short int*     | unsigned short int*     |                |            |        | short int*   |
| l      | long int*      | unsigned long int*      | double*        | wchar_t*   |        | long int*    |
| ll     | long long int* | unsigned long long int* | long long int* |            |        |              |
| j      | intmax_t*      | uintmax_t*              |                |            |        | intmax_t*    |
| z      | size_t*        | size_t*                 |                |            |        | size_t*      |
| t      | ptrdiff_t*     | ptrdiff_t*              |                |            |        | ptrdiff_t*   |
| L      |                |                         | long double*   |            |        |              |

```cpp
--8<-- "docs/syntax/code/scanf.cpp"
```

`scanf` 的參數前面需要加一個 `&` ，簡單來說就是 `scanf` 的參數是記憶體位置，要更詳細理解要先學完指標。（編者認為這是當初設計沒想到的一個 bug)。

### `printf`

`printf` 的格式碼格式為： `%[flags][width][.precision][length]specifier`

- `flags` 這裡不詳細提，可參考 [cplusplus](https://www.cplusplus.com/reference/cstdio/printf/)。
- `width` 在 `printf` 的用途為對右靠齊，如果輸出的字元數小於所設寬度，不足部分會用空白填滿；如果輸出的字元數大於所設寬度，則無效，對浮點數也無效。若無法事先知道寬度，可用 `*` 代替。
- `precision` 在 `printf` 的用途為指定輸出長度。整數部分，如果是輸出的字元數小於所設長度，不足部分會補 $0$ ；如果輸出的字元數大於所設長度，則無效。浮點數部分，所謂的輸出長度指的是小數點後的位數。若無法事先知道長度，亦可用 `*` 代替。
- `length` 和 `specifier` 同 `scanf`。

```cpp
--8<-- "docs/syntax/code/printf.cpp"
```

## C++ 輸入輸出，cin 和 cout

`cin` 和 `cout` 定義在標頭檔 `iostream` 。

`cin` 和 `cout` 並不需要先給出格式，直接輸出/輸入變數名稱即可。

`endl` 的作用是輸出換行，搭配 `cout` 使用，`\n` 可以取代。

```cpp
--8<-- "docs/syntax/code/ioInCpp.cpp"
```

### iomanip

C++ 的 cout 也有設定寬度和長度的功能，需使用到標頭檔 `iomanip` 。

- 寬度：`setw`，如果輸出的字元數小於所設寬度，不足部分會用空白填滿，或使用 `setfill` 改用其他字元補滿；如果輸出的字元數大於所設寬度，則無效。
- 長度：`setprecision`，只對浮點數有效。cout 有兩種表示方式，`scientific` 和 `fixed`，`scientific` 只會輸出有效位數，`fixed` 會將所有位數印出。

```cpp
--8<-- "docs/syntax/code/iomanip.cpp"
```
