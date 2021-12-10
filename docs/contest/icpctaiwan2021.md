# ICPC 台灣賽區 2021

## D - Largest Remainder
題意：給定 $D$ 個各位數字，可以隨意排序，求出一個數字，在 $mod\ K$ 之下有最大的值，如果有多組數字符合，輸出最大的值。

解法：狀態 DP，$dp[s][r]$ 代表在選取子集合 $s(0\le s\le 2^D-1)$ 情況下，是否有 $mod\ K=r$ 的排列，最大的餘數是 $maxR = max_{0\le k\le K}{k|dp[2^D-1][k]=1}$，另外維護 $ans[s][r]$ 為在選取子集合 $s(0\le s\le 2^D-1)$ 情況下，有 $mod\ K=r$ 的最大數字，最後的答案就是 $ans[2^D-1][maxR]$。

??? "參考程式碼"
    ```cpp
    --8<-- "docs/contest/code/icpcTaiwan2021D.cpp"
    ```