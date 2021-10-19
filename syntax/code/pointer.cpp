int *a, b; // 只有 a 是指標。

int val = 5;
int *ptr = &val; // 一維指標 ptr
int **ptr2 = &ptr; // 二維指標 ptr2

// 記憶體為動態配置，每次跑出的答案不盡相同。
// 輸出為一個 16 進位的數字，開頭為 `0x` （代表 16 進位）。
cout << ptr << '\n';

cout << (*ptr) << ' ' << val << '\n';
++(*ptr);
cout << (*ptr) << ' ' << val << '\n';