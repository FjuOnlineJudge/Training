#include <iostream>
#include <set>
#include <vector>
using namespace std;

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
        for (int L = 0, R = 0; R < n; ++R)
        {
            while (st.count(v[R]))
            {
                st.erase(v[L++]);
            }
            st.insert(v[R]);
            ans = max(ans, R - L + 1);
        }
        cout << ans << '\n';
    }
}