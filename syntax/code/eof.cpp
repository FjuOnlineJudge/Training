int x;
// scanf
while (scanf("%d", &x) != -1){}
// `EOF` 是 `C/C++` 語言的一個常數，為 `-1` ，可以用 `EOF` 代替 `-1` ，增加可讀性。
while (scanf("%d", &x) != EOF){}

// cin
while (cin.eof()){ cin >> x; }
while ((bool)cin >> x){}
while (cin >> x){}