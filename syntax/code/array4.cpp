#include <iostream>
using namespace std;
int arr1[100000]; // OK，開在全域

int main() {  
    int arr2[100000]; // 錯誤，記憶體過大
    static int arr3[100000];  // OK，加上 static 關鍵字
}