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
const int MXN = 2e5 + 5;
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
struct Node
{
    int sumUp;
    Node *lc, *rc;
    vector<int> semiStack;
    Node() : sumUp(0), lc(nullptr), rc(nullptr) {}
};
bitset<MXN> isUsed;

int getMax(Node *node)
{
    if (!node->semiStack.empty())
        return max(node->sumUp, node->semiStack.back());
    return node->sumUp;
}

int getTop(Node *node)
{
    return (node->semiStack.size() ? node->semiStack.back() : 0);
}

Node *update(Node *node, int L, int R, int qL, int qR, int val)
{
    if(!node->lc)
        node->lc = new Node();
    if(!node->rc)
        node->rc = new Node();
    if (qL <= L && R <= qR)
    {
        if (val)
            node->semiStack.push_back(val);
        return node;
    }
    int M = (L + R) >> 1;
    if (qL <= M)
        node->lc = update(node->lc, L, M, qL, qR, val);
    if (M < qR)
        node->rc = update(node->rc, M + 1, R, qL, qR, val);
    node->sumUp = max(getMax(node->lc), getMax(node->rc));
    return node;
}

int query(Node *node, int L, int R, int qL, int qR)
{
    if (qL <= L && R <= qR)
    {
        return node->sumUp;
    }
    int M = (L + R) >> 1, ret;
    if (qR <= M)
        ret = max(getTop(node->lc), query(node->lc, L, M, qL, qR));
    else if (M < qL)
        ret = max(getTop(node->rc), query(node->rc, M + 1, R, qL, qR));
    else
        ret = max(max(getTop(node->lc), query(node->lc, L, M, qL, qR)),
                  max(getTop(node->rc), query(node->rc, M + 1, R, qL, qR)));
    return ret;
}

Node *rePushUp(Node *node, int L, int R, int qL, int qR, int val)
{
    if (qL <= L && R <= qR)
    {
        while (!node->semiStack.empty() && isUsed[node->semiStack.back()])
            node->semiStack.pop_back();
        return node;
    }
    int M = (L + R) >> 1;
    if (qL <= M)
        node->lc = rePushUp(node->lc, L, M, qL, qR, val);
    if (M < qR)
        node->rc = rePushUp(node->rc, M + 1, R, qL, qR, val);
    node->sumUp = max(getMax(node->lc), getMax(node->rc));
    return node;
}

int main()
{
    IOS;
    int n, m;
    Node *root = new Node();
    cin >> n >> m;
    vector<string> name(m + 5);
    vector<int> L(m + 5), R(m + 5);
    FOR(i, 0, n) root = update(root, 0, n - 1, i, i, 0);
    isUsed.reset();
    FOR(i, 1, m + 1)
    {
        int typeID;
        cin >> typeID;
        if (typeID == 1)
        {
            string s;
            cin >> name[i] >> L[i] >> R[i];
            root = update(root, 0, n - 1, L[i], R[i], i);
        }
        else
        {
            cin >> L[i] >> R[i];
            int res = max(getTop(root),query(root, 0, n - 1, L[i], R[i]));
            if (res)
            {
                isUsed[res] = true;
                cout << name[res] << '\n';
                root = rePushUp(root, 0, n - 1, L[res], R[res], res);
            }
            else
            {
                cout << ">_<\n";
            }
        }
    }
}
