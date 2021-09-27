# 枚舉（Enumerate)

枚舉是最直觀的演算法，列出所有可能的解，並判斷是否符合題目要求。容易寫出，但通常時間複雜度太大無法滿足題目時限。

通常在設計枚舉找出需要枚舉的參數，並選擇是要用迴圈或遞迴方式。如果評估時間複雜度的時候發現太大時，可搭配一些技巧來降低時間複雜度。

## 特殊枚舉型態

### 集合

如果題目要求和集合有關係，可利用二進位表示一個集合，第 $i$ 位代表第 $i$ 樣物品選或不選 (0 或 1)。時間複雜度 $O(2^n)$ ，若執行時限為 $1$ 秒，枚舉大小最多約 $30$ 。

### 順序

如果題目要求和順序有關係，可利用 `<algorithm>` 內的 `next_permutation` 或 `prev_permutation` 達到枚舉元素的先後順序。時間複雜度為 $O(N!)$ ，若執行時限為 $1$ 秒，枚舉大小最多約 $10$ 。

## 技巧

### 減少枚舉維度

找出需要枚舉的參數後，有些參數可能是和結果無關，或是可由其他參數推導出，移除該參數可降低時間複雜度。

???+ Question "uva10976 - Fractions Again?"
    給定 $k(0 < k \leq 100)$ ，請求出所有正整數解 $x,y(x \geq y)$ ，使得 $\frac{1}{k}=\frac{1}{x}+\frac{1}{y}$ 

最直觀的解法是枚舉兩個參數 $x,y$ ，但其實只要知道 $x,y$ 任意一項就可推出另外一項，有根據題目我們可以得出 $y$ 在 $(k,2k]$ 之間（當 $x=y$ 時， $x=y=2k$ )，要枚舉的範圍較小，因此我們選擇枚舉 $y$ 的算法，時間複雜度為 $O(k)$ 

??? "參考程式碼"
    作者： [allem40306](https://github.com/allem40306) 
    
    ```cpp
    #include <iostream>
    using namespace std;
    #define N 10005
    ```

    int main(){
        int n;
        while (cin >> n){
            int ans[N][2], ar = 0;
            for (int i = n + 1; i <= 2 * n; i++){
                int r = i - n;
                if ((i*n) % r == 0){
                    ans[ar][1] = i;
                    ans[ar][0] = (i*n) / r;
                    ar++;
                }
            }
            printf("%d\n", ar);
            for (int i = 0; i < ar; i++)
                printf("1/%d = 1/%d + 1/%d\n", n, ans[i][0], ans[i][1]);
        }
    }
    ```

### 雙指標

利用兩個指標線性遍歷陣列，得出答案。「雙指標」可為兩個指標或是兩個整數型態變數紀錄位置。

???+ Question 
    給定一個長度為 $N,(N \leq 100000)$ 的序列 $A$ ，求出一組 $i,j(i>j)$ 使得 $a_i-a_j$ 最大

首先會直觀的想到一個 $O(N^2)$ 的算法：枚舉 $i,j$ 算出結果後取最大值。
接著可以想到對於每個數字 $a_i$ 只要和最小的 $a_j$ ( $min_j$ ) 相減即可，又 $min_j$ 具有單調性，即 $min_j$ 的位置會不變或向右移，因此可以利用一個指標遍歷序列，一個指標紀錄當前 $min_j$ 的位置，時間複雜度 $O(N)$ 。

??? "參考程式碼"
    作者： [allem40306](https://github.com/allem40306) 
    
    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;
    ```

    int main()
    {
        int n;
        vector<int> v(100000);
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        int minj = 0, ans = v[1] - v[0];
        for (int i = 1; i < n; ++i)
        {
            ans = max(ans, v[i] - v[minj]);
            if (v[i] < v[minj])
            {
                minj = i;
            }
        }
        cout << ans << '\n';
    }
    ```

* * *

???+ Question "11572 - Unique Snowflakes"
    給定一個長度為 $N,(N \leq 100000)$ 的序列 $A$ ，求出最長序列，當中沒有重複的數字

我們可以設兩個指標，左指標和右指標，每次迭代右指標先往前一個位置，如果左右指標之間有重複的數字，就將左指標往前一個位置，直到沒有左右指標之間沒有重複的數字。利用 `set` 來維護是否有重複數字，時間複雜度 $O(N\log N)$ 。

??? "參考程式碼"
    作者： [allem40306](https://github.com/allem40306) 
    
    ```cpp
    #include <iostream>
    #include <set>
    #include <vector>
    using namespace std;
    ```

    int main()
    {
        int t, n;
        cin >> t;
        vector<int> v(1000000);
        set<int> st;
        while (t--)
        {
            st.clear();
            cin >> n;
            for (int i = 0; i < n; ++i)
            {
                cin >> v[i];
            }
            int ans = 0;
            for (int L = 0, R = 0;R < n;++R)
            {
                while(st.count(v[R]))
                {
                    st.erase(v[L++]);
                }
                st.insert(v[R]);
                ans = max(ans, R - L + 1);
            }
            cout << ans << '\n';
        }
    }
    ```

### 折半枚舉

有時遇到複雜度 $O(2^n)$ 的算法，在無法用其他方法降低複雜度情況下，可以試著將元素切成兩半，分別算出答案，再用其他算法組合起來，時間複雜度通常為 $O(2^{\frac{n}{2}})$ 或 $O(2^{\frac{n}{2}}\log 2^{\frac{n}{2}})$ 等。

???+ Question "uva01326 - Jurassic Remains"
    給定 $N(N\leq 24)$ 串英文字串，請最多可以包含幾個字串，使得這些字串內每個字元都出現偶數次。

先把每個字串轉成一個二進位，第 $i$ 位表示字串有（0: 偶數，1: 奇數）個字元 i (0:A, 1:B, ...)。如果有一堆字串內每個字元都出現偶數次，那麼他們的 xor 值 $=0$ 。

這題關於「集合」，可用二進位枚舉，加上判斷，時間複雜度 $O(N\times 2^N)$ 。

這題更快的做法是拆半枚舉，把前 $\frac{N}{2}$ 和後 $\frac{N}{2}$ 字串分別枚舉，分別把結果存在不同的 map 裡面，如果兩個 map 有相同的 xor 值，代表兩個集合的字串合起來，每個字元都出現偶數次。這種做法時間複雜度為 $O(2^{\frac{n}{2}}\log 2^{\frac{n}{2}})$ 

### 剪枝

在使用遞迴枚舉時，當搜尋到一組解答，發現該組解和其延伸的解，皆無法達到達到需求，就停止搜尋，改搜尋其他組解，該技巧叫做「剪枝」。

明確地來說，以下狀況需使用「剪枝」：

- 發現解答是不合法的。
- 在最佳化問題，發現無法成為最佳解。

???+ Qusetion
    給定一個數字 $N$ ，要你求出有幾組正整數解 $x_1,x_2,x_3,...,x_m$ ，使得 $x_1+x_2+x_3+...+x_m = N$ 。順序不同視為相同解，例如 $1+2$ 和 $2+1$ 視為相同組解。

為了避免算到重複組合，我們讓 $x_1 \leq x_2 \leq ...$ 。

設目前解總和為 $sum$ ，最後一項為 $max$ ，下一項 $i$ 就從 $max$ 開始嘗試，當嘗試到 $sum + i > N$ 時，就停止嘗試（剪枝）。

??? "參考程式碼"
    作者： [allem40306](https://github.com/allem40306) 
    
    ```cpp
    #include <iostream>
    using namespace std;
    int ans, tar;
    ```

    void dfs(int mx, int sum)
    {
        if (sum == tar)
        {
            ++ans;
        }
        for (int i = mx;; ++i)
        {
            if (sum + i > tar)
            {
                break;
            }
            dfs(i, sum + i);
        }
        return;
    }

    int main()
    {
        // IOS;
        while (cin >> tar)
        {
            ans = 0;
            dfs(1, 0);
            cout << ans << '\n';
        }
    }
    ```
