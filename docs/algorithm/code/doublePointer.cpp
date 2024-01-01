#include <iostream>
#include <vector>
using namespace std;

        int main()
        {
            int n;
            vector<int> v(150005);
            cin >> n;
            for (int i = 0; i < n; ++i)
                cin >> v[i];
            int minj = 0, ans = v[1] - v[0];
            for (int i = 1; i < n; ++i)
            {
                ans = max(ans, v[i] - v[minj]);
                if (v[i] < v[minj])
                    minj = i;
            }
            cout << ans << '\n';
        }