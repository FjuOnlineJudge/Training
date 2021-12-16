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
double a[MXN], b[MXN], c[MXN];

double f(double x)
{
    double ret = a[0] * x * x + b[0] * x + c[0];
    FOR(i, 1, n) ret = max(ret, a[i] * x * x + b[i] * x + c[i]);
    return ret;
}

double trinary_search(double L, double R)
{
    for (int i = 0; i < 300; ++i)
    {
        double mL = (L + L + R) / 3, mR = (L + R + R) / 3;
        if (f(mR) > f(mL))
            R = mR;
        else
            L = mL;
    }
    return L;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 0, n) cin >> a[i] >> b[i] >> c[i];
        cout << fixed << setprecision(4) << f(trinary_search(0.0, 1000.0)) << '\n';
    }
}
