# 哈密頓問題

跟歐拉迴路很像，不過這次不能重複的是點。至於判斷是否存在 Hamilton Circuit、找到一個 Hamilton Circuit 是 NP-complete 問題，找到一個權重最小的 Hamilton Circuit 是 NP-hard 問題，目前尚未出現有效率的演算法。

用 DP 可以做到 $O(2^n\times n^2)$ 的複雜度。
