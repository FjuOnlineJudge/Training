#include <bits/stdc++.h>
using namespace std;
const int N = 25;

int main()
{
    int n;
    cin >> n;
    vector<int> H(n + 5), L(n + 5), R(n + 5);
    for (int i = 0; i < n; ++i)
        cin >> H[i];
    stack<int> st;
    // calculate R[]
    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && H[st.top()] > H[i])
        {
            R[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        R[st.top()] = n - 1;
        st.pop();
    }
    // calculate L[]
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && H[st.top()] > H[i])
        {
            L[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        L[st.top()] = 0;
        st.pop();
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, H[i] * (R[i] - L[i] + 1));
        cout << i << ' ' << L[i] << ' ' << R[i] << '\n';
    }
    cout << ans << '\n';
}