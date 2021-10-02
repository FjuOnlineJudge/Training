# 自定義結構

自定義結構為一些成員元素（資料）的組合體，在 `C` 有 `struct` ， `C++` 有 `struct` 和 `class` ， `C` 和 `C++` 的 `struct` 是不同的，以下講解：

##  `C` 的 `struct` 

首先一個 `struct` 的定義語法如下。裡面的成員元素可以為指標，注意右大括號後要加分號。

```cpp
struct structure_name {
  type1 name1;
  type2 name2;
  ...
}; //<-notice
```

宣告語法為：

```cpp
struct structure_name var1, var2, ...;
```

變數也可以在定義時宣告：

```cpp
struct structure_name {
  type1 name1;
  type2 name2;
  ...
} var1, var2, ...;
```

struct 也可以宣告成陣列。

```cpp
struct structure_name var1[size];
```

```cpp
struct Item {
  int price, weight;
} apple;

struct Item banana;
```

##  `C++` 的 `struct` 和 `class` 

相對於 `C` 的 `struct` ， `C++` 的 `struct` 和 `class` 有物件導向的概念。

在定義方面和 `C` 的 `struct` 相似， `C++` 的 `struct` 和 `class` 不只有成員元素，還有成員函式。

宣告方面比 `C` 的 `struct` 的差別是， `C++` 的 `struct` 和 `class` 不用在前面加上 `struct` 和 `class` 。

=== "struct"

    ```cpp
    struct Item{
        int price, weight;
        int getPrice(){
            return price;
        }
    }apple;
    Item banana;
    ```

=== "class"

    ```cpp
    class Item{
      public:
        int price, weight;
        int getPrice(){
            return price;
        }
    }apple;
    Item banana;
    ```

 `C++` 的 `struct` 和 `class` 不同的地方，在於成員的存取權限，可利用 `public` 、 `protected` 、 `private` 設定權限。

-  `public` : 所有函式可存取。
-  `protected` : 成員函式、 `friend` 類別成員或函式，以及衍生類別可存取。
-  `private` : 成員函式及 `friend` 類別成員或函式可存取。

如果不設定權限， `strcut` 成員預設為 `public` ， `class` 則是 `private` 。

```cpp
struct Item {
public:
protected:
private:
};
```

???+ info "friend 關鍵字"
    每個人社群中的好友，可以看到自己發佈的私人文章， `friend` 就同如社群中的好友，提供 `friend` 類別或函式存取該結構的元素。
    
    ```cpp
    struct Circle {
    private:
      double radius;
    ```

      friend double area(Circle&);
    };

    double area(Circle& c)
    {
        return c.radius * c.radius * 3.14;
    }
    ```

???+ info "衍生類別"
    衍生類別是物件導向的概念，如果 `B` 是一種 `A` ， `B` 就是 `A` 的衍生類別， `A` 就是 `B` 的基礎類別。

    例如「汽車」是一種「交通工具」，那麼「汽車」就是「交通工具」的衍生類別，「交通工具」就是「汽車」的基礎類別。

## 訪問元素

如果是 `struct` 的變數 `var` ，用 `var.name` 。
如果是 `struct` 的指標變數 `ptr` ，用 `ptr->name` 或 `(*ptr).name` 。

## 特殊函式

 `C++` 的 `struct` 和 `class` 、有些比較特殊的函式，分別為建構函式、解構函式、運算子多載 (operator overloading)。

```cpp
struct Plane {
  int x, y;
  // 建構函式
  Plane(){};
  Plane(int _x, int _y) : x(_x), y(_y) {}
  Plane add(const Plane &rhs) const { return Plane(x + rhs.x, y + rhs.y); }
  // 運算子多載
  bool operator<(const Plane &rhs) const {
    if (x != rhs.x)
      return x < rhs.x;
    return y < rhs.y;
  }
  // 解構函式
  ~Plane(){};
};
int main() {
  Plane p1;
  Plane p2(1, 2);
  Plane p3 = Plane();
  Plane p4 = Plane(0, 0);
}
```

### 建構函式 (constructor)、解構函式 (destructor)

建構函式同名結構的名稱，是用來初始化結構裡的資料，如果不寫的話，會有預設建構函式，裡面的資料都是亂數。根據情況可多載。然而，如果結構有運算函式多載，一定要寫一個不帶任何參數的運算函式，否則的話，像第 14 行這樣只有宣告，沒加其他東西的的程式碼就不會通過。

解構函式的名字形式為 `~` + 結構的名稱，是在變數離開作用域時運作，不寫的話也是會有預設解構函式，在程式比賽中絕大部分的狀況，不用特別寫解構函式。

建構函式和解構函式的權限必為 `public` 。

### 運算子多載

c++ 原有的型態都根據需要，定義了各種運算子，但 struct 如果有需要的話，須自己定義。而在競賽中，常需要作排序而需要小於運算子（ `<` )。

???+ info "覆載 (override) 和"
    覆載 (override) 是指在衍生類別重新改寫同名寫「參數相同」的函式。
    
    ```cpp
    struct Transportation {
      string color;
      void printColor() {
        cout << "The transportation's color is " + color + ".\n";
      }
    };
    ```

    struct Car: Transportation{
        void printColor()
        {
            cout << "The car's color is " + color + ".\n";
        }   
    };
    ```

    多載 (overload) 是指在重新改寫同名寫「參數不同」的函式。

    ```cpp
    struct Transportation{
        string color;
        void printColor()
        {
            cout << "The transportation's color is " + color + ".\n";
        }
        void printColor(int year)
        {
            cout << "These transportation was made in" + year + ".\n";
            cout << "These transportation's color is " + color + ".\n";
        }       
    };
    ```

## 大小

結構的大小，並非為所有元素相加， `C/C++` 的結構大小配置會進行「對齊的最佳化」。struct 會分成很多塊存放，每一塊會是最大元素的大小為對齊基準，元素會依宣告的順序擺放，連續的元素會放在同一塊，如果不夠空間擺放才會放在下一塊。

以下例子作為說明，在這裡，我們 `sizeof` 這個運算子求出結構的大小。

```cpp
struct Data1 {
  char ch1;
  int i;
  char ch2;
};

struct Data2 {
  char ch1;
  char ch2;
  int i;
};

int main() {
  cout << sizeof(Data1) << '\n'; // 12
  cout << sizeof(Data2) << '\n'; // 8
}
```

 `Data1` 和 `Data2` 當中最大元素大小為 4 ( `int` )。 `Data1` ，用了 $3$ 塊來存 $1$ 個 `struct` ，第一塊存 `char ch1` ，第二塊存 `int i` ，第三塊存 `char ch2` ，因此大小為 $12$ ； `Data2` ，用了 $3$ 塊來存 $2$ 個 `struct` ，第一塊存 `char ch1` 和 `char ch2` ，第二塊存 `int i` ，因此大小為 $8$ 。

## 為什麼要用自定義結構

資料存放有很多種方法，可以利用開多個陣列來取代自定義結構，但有些操作會直接將資料移動，包含排序和刪除，如果用多個陣列儲存，需要確保每個陣列的資料都被正確的移動；使用結構，就不用去維護這件事情。

再來是多個結構可能會有相同名稱的成員元素。例如 apple 和 banana，它們都有一個成員元素 price，如果用多個陣列儲存，它們不能共用同一個陣列 `price[]` ，要寫成 `priceOfApple` 和 `priceOfBanana` ；如果用結構，就可以讓不同結構擁有相同名稱的成員元素（例如 `a.price` 和 `b.price` ) 來區分。

[^1]:  [Override 與 Overload 的差別 - 橘子亂說話](https://wayne265265.pixnet.net/blog/post/115533452-%E3%80%90%E6%95%99%E5%AD%B8%E3%80%91override-%E8%88%87-overload-%E7%9A%84%E5%B7%AE%E5%88%A5) 

[^2]:  [定義結構 - openhome.cc](https://openhome.cc/Gossip/CGossip/StructABC.html) 

[^3]:  [How To Calculate Size Of Structure And Class in C & C++ - CppNuts in Youtube](https://www.youtube.com/watch?v=0MfaKi88Zjo) 

[^4]:  [结构体 - OI Wiki](https://oi-wiki.org/lang/struct/) 
