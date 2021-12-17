# 其他語法

## `define`
類似 excel 中的巨集，用於取代程式中出現的特定字元(可帶參數)，可建立縮寫或定義常數，後者較適合用 `const` 實現。為了要讓結果保持正確，請將取代後的字元括號起來，否則會輸出非預期的結果。

```cpp
--8<-- "docs/syntax/code/define.cpp"
```

## `const`
用於建立常數。

```cpp
--8<-- "docs/syntax/code/const.cpp"
```

## range based `for`
不用給出明確的開啟和結束條件，就能遍歷整個容器。如果要修改元素，變數需宣告成參考型態。

```cpp
--8<-- "docs/syntax/code/rangeBaseFor.cpp"
```

## `auto`
可以自動判別變數型態，但必須給他初始值，否則他無法判別型態，`C++14` 開始，可用在函式回傳值。

```cpp
--8<-- "docs/syntax/code/auto.cpp"
```

## `typedef` 和 `using`
`typedef` 可以為型態取別名，在之後用到要宣告該型態的時候，可以打該型態之別名。`C++11` 開始可以用 `using` 來達到相同的事。

```cpp
--8<-- "docs/syntax/code/typeAlias.cpp"
```

## lambda
定義匿名函式。

- lambda-introducer：也叫 Capture clause，宣告外部變數(在可視範圍(scope)內)傳入此函式內的方法。

???+ "方法"
    - `[]`：完全不抓取外部的變數。
    - `[=]`：所有的變數都以傳值 (call by value) 的方式抓取。
    - `[&]`：所有的變數都以傳參考 (call by reference) 的方式抓取。
    - `[x,&y]`：`x` 變數使用傳值，`y` 變數使用傳參考。
    - `[=,&y]`：除了 `y` 變數使用傳參考以外，其餘的變數皆使用傳值的方式。
    - `[&,x]`：除了 `x` 變數使用傳值以外，其餘的變數皆使用傳參考的方式。

- lambda declarator：也叫參數清單，傳入此函式對應資料。
- mutable specification：指定以傳值方式抓取進來的外部變數，可省略。

???+ "限制"
    - 不可指定參數的預設值。
    - 不可使用可變長度的參數列表。
    - 參數列表不可以包含沒有命名的參數。

- 例外狀況規格：指定該函示會丟出的例外，其使用的方法跟一般函數的例外指定方式一樣，可省略。
- 傳回值型別：指定 lambda expression 傳回型別，如果 lambda expression 所定義的函數很單純，只有包含一個傳回陳述式（statement）或是根本沒有傳回值的話，可省略。
- compound-statement：亦稱為 Lambda 主體(lambda body)，跟一般的函數內容一樣。

## `<bits/stdc++.h>`

`<bits/stdc++.h>` 是 C++ 一個 include 所有其他函式庫的一個函式庫。

優點是方便，不用另外 include 其他函式庫。

但有幾個缺點，可以參考 [這篇](https://codeforces.com/blog/entry/51856)，其中提到 當用這個函式庫，`y1` 可能在某些 OJ 會遇到 `Compilation Error`。