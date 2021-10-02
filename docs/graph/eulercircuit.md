# 歐拉迴路

???+ Question "歐拉迴路"
    柯尼斯堡七橋問題可說是圖論最早的起源，問題如下（from 維基百科）："當時東普魯士柯尼斯堡（今日俄羅斯加里寧格勒）市區跨普列戈利亞河兩岸，河中心有兩個小島。小島與河的兩岸有七條橋連接。在所有橋都只能走一遍的前提下，如何才能把這個地方所有的橋都走遍？" 歐拉解決這個問題，圖論也因此誕生。

七橋問題根據起點與終點是否相同，分成 Euler path (不同) 及 Euler circuit (相同)。

## 判斷法

無向圖部分，將點分成奇點（度數為奇數）和偶點（度數為偶數）。

- Euler path：奇點數為 0 或 2
- Euler circuit：沒有奇點

??? "證明 from wiki"
    必要性：如果一個圖能一筆畫成，那麼對每一個頂點，要麼路徑中「進入」這個點的邊數等於「離開」這個點的邊數：這時點的度為偶數。要麼兩者相差一：這時這個點必然是起點或終點之一。注意到有起點就必然有終點，因此奇頂點的數目要麼是 0，要麼是 2。
    充分性：如果圖中沒有奇頂點，那麼隨便選一個點出發，連一個環 $C_{1}$ 。如果這個環就是原圖，那麼結束。如果不是，那麼由於原圖是連通的，$ C\_{1}$ 和原圖的其它部分必然有公共頂點 $s\_{1}$ 。從這一點出發，在原圖的剩餘部分中重複上述步驟。由於原圖是連通圖，經過若干步後，全圖被分為一些環。由於兩個相連的環就是一個環，原來的圖也就是一個歐拉環了。如果圖中有兩個奇頂點 $u$ 和 $v$ ，那麼加多一條邊將它們連上後得到一個無奇頂點的連通圖。由上知這個圖是一個環，因此去掉新加的邊後成為一條路徑，起點和終點是 $u$ 和 $v$ 。證畢。

有向圖部分，將點分成出點（出度 - 入度 = 1）和入點（入度 - 出度 = 1）還有平衡點（出度 = 入度）。

- Euler path：出點和入點個數同時為 0 或 1。
- Euler circuit：只有平衡點。

???+ Question "UVa 10129 - Play on Words"
    給定 $N$ 個字串，如果一個字串的字尾和另一個字串的字首相同，可以把這兩個字串相連，問是否存在一種辦法可以把所有字串相連。

把英文字母當作點，對於每個字串 $S$，將 $S$ 頭尾兩個字母之間連一條有向邊，這題題目就轉成判斷一張有向圖是否存在 Euler path (circuit)，此外要判斷這張圖是否為一張連通圖。

??? "參考程式碼"
    ```cpp
    #pragma GCC optimize("O2")
    #include <bits/stdc++.h>
    using namespace std;
    using LL = long long;
    using ULL = unsigned long long;
    using PII = pair<int, int>;
    using PLL = pair<LL, LL>;
    using VI = vector<int>;
    using VVI = vector<vector<int>>;
    const int INF = 1e9;
    const int MXN = 0;
    const int MXV = 30;
    const double EPS = 1e-9;
    const int MOD = 1e9 + 7;
    #define MP make_pair
    #define PB push_back
    #define F first
    #define S second
    #define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
    #define FORD(i, L, R) for (int i = L; i > (int)R; --i)
    #define IOS                                                                    \
        cin.tie(nullptr);                                                          \
        cout.tie(nullptr);                                                         \
        ios_base::sync_with_stdio(false);
    vector<int> din(MXV), dout(MXV);
    vector<int> G[MXV];
    bitset<MXV> vis;

    void init()
    {
        fill(din.begin(), din.end(), 0);
        fill(dout.begin(), dout.end(), 0);
        FOR(i, 0, MXV) G[i].clear();
        vis.reset();
    }

    void dfs(int u)
    {
        vis[u] = true;
        for (int v : G[u])
            if (!vis[v])
                dfs(v);
    }

    bool ok(int st)
    {
        int cnt1 = 0, cnt2 = 0;
        FOR(i, 0, MXV)
        {
            int d = dout[i] - din[i];
            if (d == 1)
            {
                ++cnt1;
                st = i;
            }
            else if (d == -1)
                ++cnt2;
            else if (d != 0)
                return false;
        }
        if (cnt1 != cnt2 || cnt1 > 1)
            return false;
        dfs(st);
        FOR(i, 0, MXV)
        {
            if ((din[i] || dout[i]) && !vis[i])
                return false;
        }
        return true;
    }

    int main()
    {
        IOS;
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            string s;
            cin >> n;
            init();
            FOR(i, 0, n)
            {
                cin >> s;
                int u = s[0] - 'a', v = s.back() - 'a';
                ++dout[u];
                ++din[v];
                G[u].emplace_back(v);
            }
            if (ok(s[0] - 'a'))
                cout << "Ordering is possible.\n";
            else
                cout << "The door cannot be opened.\n";
        }
    }
    ```

## 求出一組解

用 DFS 遍歷整張圖，設 $S$ 為離開的順序，無向圖的答案為 $S$，有向圖的答案為反向的 $S$。

DFS 起點選定：

- Euler path：無向圖選擇任意一個奇點，有向圖選擇出點。
- Euler circuit：任意一點。

???+ Question "UVa 10441 - Catenyms"
    給定 $N$ 個字串，如果一個字串的字尾和另一個字串的字首相同，可以把這兩個字串相連，問是否存在一種辦法可以把所有字串相連。如果存在解，請輸出擁有最小字典序的解。

這題判斷是否有解的做法和上的例題相似，差別在於這裡用並查集判斷是否為連通圖。這題需求出擁有最小字典序的解，因此要把字串排序。

??? "參考程式碼"
    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    const int ALP = 30;
    const int MXN = 1005;
    int n;
    int din[ALP], dout[ALP];
    int par[ALP];
    vector<string> vs[MXN], ans;
    bitset<MXN> vis, used[ALP];

    void djsInit()
    {
        for (int i = 0; i != ALP; ++i)
        {
            par[i] = i;
        }
    }

    int Find(int x) { return (x == par[x] ? (x) : (par[x] = Find(par[x]))); }

    void init()
    {
        djsInit();
        memset(din, 0, sizeof(din));
        memset(dout, 0, sizeof(dout));
        vis.reset();
        for (int i = 0; i != ALP; ++i)
        {
            vs[i].clear();
            used[i].reset();
        }
        return;
    }

    void dfs(int u)
    {
        for (int i = 0; i != (int)vs[u].size(); ++i)
        {
            if (used[u][i])
            {
                continue;
            }
            used[u][i] = 1;
            string s = vs[u][i];
            int v = s[s.size() - 1] - 'a';
            dfs(v);
            ans.push_back(s);
        }
    }

    bool solve()
    {
        int cnt = 1;
        for (int i = 0; i != n; ++i)
        {
            string s;
            cin >> s;
            int from = s[0] - 'a', to = s.back() - 'a';
            ++din[to];
            ++dout[from];
            vs[from].push_back(s);
            vis[from] = vis[to] = true;
            if ((from = Find(from)) != (to = Find(to)))
            {
                par[from] = to;
                ++cnt;
            }
        }
        if ((int)vis.count() != cnt)
        {
            return false;
        }
        int root, st, pin = 0, pout = 0;
        for (int i = ALP - 1; i >= 0; --i)
        {
            sort(vs[i].begin(), vs[i].end());
            if (vs[i].size())
                root = i;
            int d = dout[i] - din[i];
            if (d == 1)
            {
                ++pout;
                st = i;
            }
            else if (d == -1)
            {
                ++pin;
            }
            else if (d != 0)
            {
                return false;
            }
        }
        if (pin != pout || pin > 1)
        {
            return false;
        }
        ans.clear();
        dfs((pin ? st : root));
        return true;
    }

    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            cin >> n;
            init();
            if (!solve())
            {
                cout << "***\n";
                continue;
            }
            for (int i = ans.size() - 1; i >= 0; --i)
            {
                cout << ans[i] << ".\n"[i == 0];
            }
        }
    }
    ```

## 哈密頓問題

跟歐拉迴路很像，不過這次不能重複的是點。至於判斷是否存在 Hamilton Circuit、找到一個 Hamilton Circuit 是 NP-complete 問題，找到一個權重最小的 Hamilton Circuit 是 NP-hard 問題，目前尚未出現有效率的演算法。

用 DP 可以做到 $O(2^n\times n^2)$ 的複雜度。
