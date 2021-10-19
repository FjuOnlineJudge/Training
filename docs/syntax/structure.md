# 自定義結構

自定義結構為一些成員元素（資料）的組合體，在 `C` 有 `struct` ， `C++` 有 `struct` 和 `class` ， `C` 和 `C++` 的 `struct` 是不同的，以下講解：

##  `C` 的 `struct` 

- 定義：`{}` 之間存放成員元素，成員元素可以示指標或陣列，`}` 之後要加上 `;`。
- 宣告：宣告可在定義時宣告(`Line 6`)，也可以獨立宣告一行 (`Line 8-10`)，相似地，可以宣告為指標或是陣列。

```cpp
--8<-- "docs/syntax/code/strcutureInC.cpp"
```

##  `C++` 的 `struct` 和 `class` 

`C++` 的 `struct` 和 `class` 導入物件導向的概念，除了成員元素，還可定義成員函式。獨立宣告時，不用在前面加上 `struct` 和 `class` 。

`C++` 的 `struct` 和 `class` 的差異在於成員的預設存取權限，有 `public` 、 `protected` 、 `private` 三種權限，`strcut` 成員預設為 `public` ， `class` 則是 `private` 。

-  `public` : 所有函式可存取。
-  `protected` : 成員函式、 `friend` 類別成員或函式，以及衍生類別可存取。
-  `private` : 成員函式及 `friend` 類別成員或函式可存取。

```cpp
--8<-- "docs/syntax/code/strcutureInCpp.cpp"
```

???+ info "friend 關鍵字"
    每個人社群中的好友，可以看到自己發佈的私人文章， `friend` 就同如社群中的好友，提供 `friend` 類別或函式存取該結構的元素。

    ```cpp
    --8<-- "docs/syntax/code/friend.cpp"
    ```

???+ info "衍生類別"
    衍生類別是物件導向的概念，如果 `B` 是一種 `A` ， `B` 就是 `A` 的衍生類別， `A` 就是 `B` 的基礎類別。

    例如「汽車」是一種「交通工具」，那麼「汽車」就是「交通工具」的衍生類別，「交通工具」就是「汽車」的基礎類別。

## 訪問元素

對於一般變數 `var` ，用 `var.name` 。
對於指標變數 `ptr` ，用 `ptr->name` 或 `(*ptr).name` 。

## 覆載 (Override) 和多載 (Overload)

覆載 (Override) 是指在衍生類別重新改寫同名寫「參數相同」的函式。

多載 (Overload) 是指在重新改寫同名寫「參數不同」的函式。

```cpp
--8<-- "docs/syntax/code/overrideandOverload.cpp"
```

## 建構函式 (Constructor)、解構函式 (Destructor)

建構函式結構的名稱相同，是用來初始化結構裡的資料，如果沒有任何建構函式，會自動產生一個無參數的預設建構函式。然而，如果有一個帶參數的建構函式，就不會自動產生一個無參數的預設建構函式，這時候要寫一個不帶任何參數的運算函式，否則可能導致程式在編譯時發生錯誤。

解構函式的名字形式為 `~結構的名稱`，在變數離開作用域時運作，不寫的話也是會有預設解構函式，在程式比賽中絕大部分的狀況，不用特別寫解構函式。

建構函式和解構函式的存取權限必為 `public` 。

## 多載運算子(Operator overloading)

`C/C++` 定義了各種運算子，自定義結構根據需求可以多載運算子。在競賽中，常需要作排序而需要多載小於運算子（ `<` )。

```cpp
--8<-- "docs/syntax/code/plane.cpp"
```

## 長度

結構的長度，並非為所有元素相加， `C/C++` 的結構長度配置會進行「對齊的最佳化」。struct 會分成很多塊存放，每一塊會是最大元素的長度為對齊基準，元素會依宣告的順序擺放，連續的元素會放在同一塊，如果不夠空間擺放才會放在下一塊。

以下例子作為說明，在這裡，我們 `sizeof` 這個運算子求出結構的長度。

```cpp
--8<-- "docs/syntax/code/structureSize.cpp"
```

 `Data1` 和 `Data2` 當中最大元素長度為 4 ( `int` )。 `Data1` ，用了 $3$ 塊來存 $1$ 個 `struct` ，第一塊存 `char ch1` ，第二塊存 `int i` ，第三塊存 `char ch2` ，因此長度為 $12$ ； `Data2` ，用了 $3$ 塊來存 $2$ 個 `struct` ，第一塊存 `char ch1` 和 `char ch2` ，第二塊存 `int i` ，因此長度為 $8$ 。

## 為什麼要用自定義結構

資料存放有很多種方法，可以利用開多個陣列來取代自定義結構，但有些操作會直接將資料移動，包含排序和刪除，如果用多個陣列儲存，需要確保每個陣列的資料都被正確的移動；使用結構，就不用去維護這件事情。

再來是多個結構可能會有相同名稱的成員元素。例如 apple 和 banana，它們都有一個成員元素 price，如果用多個陣列儲存，它們不能共用同一個陣列 `price[]` ，要寫成 `priceOfApple` 和 `priceOfBanana` ；如果用結構，就可以讓不同結構擁有相同名稱的成員元素（例如 `a.price` 和 `b.price` ) 來區分。

[^1]:  [Override 與 Overload 的差別 - 橘子亂說話](https://wayne265265.pixnet.net/blog/post/115533452-%E3%80%90%E6%95%99%E5%AD%B8%E3%80%91override-%E8%88%87-overload-%E7%9A%84%E5%B7%AE%E5%88%A5) 

[^2]:  [定義結構 - openhome.cc](https://openhome.cc/Gossip/CGossip/StructABC.html) 

[^3]:  [How To Calculate Size Of Structure And Class in C & C++ - CppNuts in Youtube](https://www.youtube.com/watch?v=0MfaKi88Zjo) 

[^4]:  [结构体 - OI Wiki](https://oi-wiki.org/lang/struct/) 
