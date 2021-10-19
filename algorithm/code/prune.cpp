#include <iostream>
using namespace std;
int ans, tar;

void dfs(int mx, int sum)
{
    if (sum == tar)
    {
        ++ans;
    }
    for (int i = mx;; ++i)
    {
        if (sum + i > tar)
        {
            break;
        }
        dfs(i, sum + i);
    }
    return;
}

int main()
{
    while (cin >> tar)
    {
        ans = 0;
        dfs(1, 0);
        cout << ans << '\n';
    }
}