#include <iostream>
using namespace std;
const int N = 100; // 全域變數
int var1 = 1;      // 全域變數

void print_var1() { cout << var1 << '\n'; }

int main()
{
    int var2 = N;                  // 區域變數
    for (int i = 0; i < var2; ++i) // 區塊變數
    {
        ++var1;
        print_var1();
    }
}