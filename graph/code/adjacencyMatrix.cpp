#include <bitset>
#include <iostream>
using namespace std;
int adj[105][105];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ':';
        for (int j = 1; j <= n; ++j)
        {
            if (adj[i][j])
            {
                cout << ' ' << j;
            }
        }
        cout << '\n';
    }
}