# 指標

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