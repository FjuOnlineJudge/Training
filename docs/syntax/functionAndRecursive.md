# 函式與遞迴
函式為程式裡的運算單元，可以接受資料，並回傳指定值。main是C/C++程式的入口函式，接受命令列的參數，正常情況會回傳0代表正常運作。
以下為其語法
```cpp
return_type function_name(parameter list){
    Do something...
    return data;// void need not return;
}
```
範例
```cpp
int sum(int x, int y){
    int sum=0;
    sum+=x;
    sum+=y;
    reutnr x+y;
}
```
函式有個特性為自呼叫，也就是自己的區域可以呼叫自己，但要有終止條件，不然會陷入無限遞迴，同時也要避免遞迴過深，造成stack overflow。
```cpp
int ans;
void f(int i){
    if(i==1){
        ans=1;
        return;
    }
    f(i-1);
    ans*=i;
    return;
}
```

## 參考
參考型態代表一個變數的別名，可直接取得變數的位址，並間接透過參考型態別名來操作物件， 作用類似於指標，但卻不必使用指標語法，也就是不必使`*`運算子來提取值。
```cpp
const int N=100;
int a[N][N];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        int &x=a[i][j];
        x=i+j;
    }
}
```
參考型態可用在取代太長的變數(如：`a[x][y][z]`)，容易維護。另一個是當函式要傳入可修改的值，可取代指標。
## 傳值
函式傳入的參數，可以是一般、指標或是參考型態，以下以Swap來介紹
### call by value
傳入的變數為一般型態，會"複製"一份到函式，原本的變數不會有任何改變。
```cpp
void swap(int x,int y){
    cout<<x<<' '<<y<<'\n';// 1 2
    int t=x;
    x=y;
    y=t;
    cout<<x<<' '<<y<<'\n';// 2 1
} 
int main(){
    int a=1,b=2;
    cout<<a<<' '<<b<<'\n';// 1 2
    swap(a,b);
    cout<<a<<' '<<b<<'\n';// 1 2
}
```
### call by address/value of pointer
傳入的變數為指標型態，函式內的變數改變，是對記憶體操作，所以原本的數字也會跟著改變。
```cpp
void swap(int *x,int *y){
    cout<<*x<<' '<<*y<<'\n';// 1 2
    int t=*x;
    *x=*y;
    *y=t;
    cout<<*x<<' '<<*y<<'\n';// 2 1
} 
int main(){
    int a=1,b=2;
    cout<<a<<' '<<b<<'\n';// 1 2
    swap(&a,&b);
    cout<<a<<' '<<b<<'\n';// 2 1
}
```
### call by reference
傳入的變數為參考型態，函數內的變數是原本變數的分身，所以函數內變數改變時，原本變數也會跟者改變。
```cpp
void swap(int &x,int &y){
    cout<<x<<' '<<y<<'\n';// 1 2
    int t=x;
    x=y;
    y=t;
    cout<<x<<' '<<y<<'\n';// 2 1
} 
int main(){
    int a=1,b=2;
    cout<<a<<' '<<b<<'\n';// 1 2
    swap(a,b);
    cout<<a<<' '<<b<<'\n';// 2 1
}
```

函式有很多用處，一個為模組化，意即相同的部分(最多只差一些參數)，寫成一個函式，除了簡潔，在除錯也比較方便。一個是利用自呼叫特性實作遞迴，遞迴可將問題拆解成同類的子問題而解決問題。
* 常見遞迴使用
    * 分治
    * dp中的top-down
    * 圖/樹的搜索