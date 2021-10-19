#include <iostream>
using namespace std;
#define N 10005

int main()
{
    int n;
    while (cin >> n)
    {
        int ans[N][2], ar = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            int r = i - n;
            if ((i * n) % r == 0)
            {
                ans[ar][1] = i;
                ans[ar][0] = (i * n) / r;
                ar++;
            }
        }
        printf("%d\n", ar);
        for (int i = 0; i < ar; i++)
            printf("1/%d = 1/%d + 1/%d\n", n, ans[i][0], ans[i][1]);
    }
}