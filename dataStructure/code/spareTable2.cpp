// 預處理
p2[0] = 1;
lg2[1] = 0;
lg2[2] = 1;
for(int i = 0; i < LOG; ++i) p2[i] = p2[i - 1] << 1;
for(int i = 3; i < MXN; ++i) lg2[i] = lg2[(i >> 1)] + 1;

// 查詢
int L, R;
cin >> L >> R;
int lg = lg2[R - L + 1];
cout << max(sp[lg][L], sp[lg][R - p2[lg] + 1]) << '\n';