#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    vector<int> G[105];
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ':';
        sort(G[i].begin(), G[i].end());
        for (int j = 0; j != (int)G[i].size(); ++j)
        {
            cout << ' ' << G[i][j];
        }
        cout << '\n';
    }
}
```

    == = "範例3 (Adjacency Matrix)"

        ```cpp
#include <algorithm>
#include <iostream>
#include <vector>
    using namespace std;
int main()
{
    int n, m;
    vector<int> G[105];
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ':';
        sort(G[i].begin(), G[i].end());
        /*for(int j = 0; j != (int)G[i].size(); ++j)
        {
            int v = G[i][j];
            cout << ' ' << v;
        }*/
        for (auto v : G[i])
        {
            cout << ' ' << v;
        }
        cout << '\n';
    }
}