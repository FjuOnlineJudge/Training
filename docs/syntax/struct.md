# struct
struct 可將原本獨立的資料包在一起。例如：三維空間由x座標、y座標、z座標組成。
* 語法
    * 型態(type)可以是一般或是指標型態
    * 也可以寫函式或重載運算子
```cpp
struct struct_name{
    type1 name1;
    type2 name2;
    ...
}; //<-notice
```
以下的例子為平面上的點。
```cpp
struct Plane{
    int x,y;
    Plane(){};
    Plane(int _x,int _y):x(_x),y(_y){}
    Plane add(const Plane &rhs)const{
        return Plane(x+rhs.x,y+rhs.y);
    }
    bool operator<(const Plane &rhs)const{
        if(x!=rhs.x)return x<rhs.x;
        return y<rhs.y;
    }
    ~Plane(){};
}
int main(){
    Plane p1;
    Plane p2(1,2);
    Plane p3=Plane();
    Plane p4=Plane(0,0);
}
```
## 建構子(constructor)、解構子(destructor)
建構子和strcut name同名，是用來初始化struct裡的資料，如果不寫的話，會有預設建構子，裡面的資料都是亂數。根據請況可多載，然而，如果你寫了運算子，一定要寫一個不帶任何參數的運算子，否則的話，像第14行這樣只有宣告，沒加其他東西的的程式碼就不會通過。
解構子的名字形式為 `~strcut name`，是在變數離開作用域時運作，不寫的話也是會有預設解構子，在程式比賽中這樣就已足夠。
## 重載運算子
c++原有的型態都根據需要，定義了各種運算子，但 struct 如果有需要的話，須自己定義。而在競賽中，常需要作排序而需要小於運算子(`<`)。