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
const int MXN = 1e4 + 5;
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
int n;
double L;
double vr[MXN], vk[MXN];

double f(double r)
{
    double t = r / vr[n - 1] + (L - r) / vk[n - 1];
    double ret = r / vr[0] + (L - r) / vk[0];
    FOR(i, 1, n - 1) ret = min(ret, r / vr[i] + (L - r) / vk[i]);
    return ret - t;
}

double trinary_search(double L, double R) // find max
{
    for (int i = 0; i < 300; ++i)
    {
        double mL = (L + L + R) / 3, mR = (L + R + R) / 3;
        if (f(mL) > f(mR))
            R = mR;
        else
            L = mL;
    }
    return L;
}

int main()
{
    while (cin >> L >> n)
    {
        FOR(i, 0, n) cin >> vr[i] >> vk[i];
        double ansL = trinary_search(0.0, L);
        double ansT = f(ansL);
        if (ansT < 0.00)
            printf("The cheater cannot win.\n");
        else
            printf("The cheater can win by %.0lf seconds with r = %.2lfkm and "
                   "k = %.2lfkm.\n",
                   ansT * 3600.0, ansL, L - ansL);
    }
}
