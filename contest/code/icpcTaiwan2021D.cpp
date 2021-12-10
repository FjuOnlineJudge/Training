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
const int MXV = 0;
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
int a[16];
bool dp[(1 << 16)][205];
LL ans[(1 << 16)][205];

int main()
{
    // IOS;
    int d, k;
    cin >> d >> k;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    FOR(i, 0, d) cin >> a[i];
    FOR(i, 0, d + 1) FOR(j, 0, (1 << d))
    {
        if (__builtin_popcount(j) != i)
            continue;
        bitset<20> used(j);
        FOR(s, 0, d) if (used[s] == false)
        {
            int nj = (j + (1 << s));
            FOR(r, 0, k)
            {
                int nr = (r * 10 + a[s]) % k;
                if (dp[j][r] == false)
                    continue;
                // cout << r << ' ' << a[s] << ' ' << k << '\n';
                // cout << nj << ' ' << nr << '\n';
                dp[nj][nr] = true;
                LL tmp = ans[j][r] * 10 + a[s];
                // cout << ans[nj][nr] << ' ' << tmp << '\n';
                if (ans[nj][nr] < tmp)
                    ans[nj][nr] = tmp;
            }
        }
    }
    FORD(i, k - 1, 0 - 1)
    {
        if (dp[(1 << d) - 1][i])
        {
            cout << ans[(1 << d) - 1][i];
            break;
        }
    }
}
