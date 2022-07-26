#include <bits/stdc++.h>
using namespace std;
const int MXN = 10005;

int main()
{
    int n, t;
    vector<int> v(MXN);
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cin >> t;
        sort(v.begin(), v.begin() + n);
        for (int i = 1; i < n; i++)
        {
            auto it = lower_bound(v.begin(), v.begin() + i, t - v[i]);
            if (it != v.begin() + i && *it == t - v[i])
            {
                cout << "Peter should buy books whose prices are " << t - v[i]
                     << " and " << v[i] << ".\n\n";
                break;
            }
        }
    }
}
