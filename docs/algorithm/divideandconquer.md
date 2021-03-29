# 分治

分治法會把問題分解成子問題（分），解決完再合併回原本的問題（治）。\\分治分成以下步驟

- 切割：把一個問題切成子問題然後遞迴
- 終止條件：停止切割，算出答案回傳。
- 合併：利用傳回來的子問題算出答案然後回傳

## 合併排序法

- 切割：把序列分成兩半然後遞迴。
- 終止條件：直到序列長度為 1，這時候已為一個排好的序列，直接回傳。
-   合併：利用傳回來的兩序列（左序列、右序列）進行排序。合併的方法為比較兩序列最左邊的元素，較小的元素排在前頭，要特別注意某個序列為空的情況。
      實作時需多開一個陣列暫存，開兩個整數 $L,R$ 分別維護左右序列目前比較的位置。

合併排序法是穩定的演算法，會遞迴 $\log N$ 層，合併的時間複雜度為 $O(N)$ ，因此時間複雜度為 $O(N\log N)$ 。

```cpp
using namespace std;
const int N = 100;
int arr[N], buf[N];
void sol(int L, int R) { // [L,R)
  if (R - L <= 1)
    return;
  int M = (R + L) / 2;
  sol(L, M);
  sol(M, R);
  int i = L, j = M, k = L;
  while (i < M || j < R) {
    if (i >= M)
      buf[k] = arr[j++];
    else if (j >= R)
      buf[k] = arr[i++];
    else {
      if (arr[i] <= arr[j])
        buf[k] = arr[i++];
      else {
        buf[k] = arr[j++];
      }
    }
    k++;
  }
  for (int k = L; k < R; k++)
    arr[k] = buf[k];
  return;
}
```

???+ "經典題目 逆序數對"
    給定一個長度為 $N$ 的序列，求有幾組數對 $i,j$ 滿足 $i < j$ 且 $a_i > a_j$ 。

    ??? "解題思路"
        這題我們可以轉換成，給定一個序列 $N$，在只能將相鄰位置交換的情況下，需要換幾次才能將序列從小排到大。
        交換次數可以在合併排序法的「合併」程式碼中計算，只要右序列有元素小於前面的元素，就會形成逆序數對，也就是上面範例程式碼 `arr[i]>arr[j]` 的情況，這時候每一個左序列尚未排序完畢的元素，都會和 `arr[j]` 形成逆序數對。
    ??? "參考程式碼"
        作者：[allem40306](https://github.com/allem40306)
        ```cpp
        #include <iostream>
        #include <cstdio>
        #include <cstring>
        using namespace std;
        #define L 500010
        int arr[L], buf[L];

        long long sol(int left, int right) {
          if (right - left <= 1)return 0;
          int middle = (right + left) / 2;
          long long ans = sol(left, middle) + sol(middle, right);
          int i = left, j = middle, k = left;
          while (i < middle || j < right) {
            if (i >= middle)
              buf[k] = arr[j++];
            else if (j >= right)
              buf[k] = arr[i++];
            else {
              if (arr[i]<=arr[j])
                buf[k] = arr[i++];
              else {
                buf[k] = arr[j++];
                ans += middle - i;
              }
            }
            k++;
          }
          for (int k = left; k < right; k++)
            arr[k] = buf[k];
          return ans;
        }

        int main() {
          int n;
          while (cin >> n, n){
            memset(arr, 0, sizeof(arr));
            memset(buf, 0, sizeof(buf));
            for (int i = 0; i < n; i++)cin >> arr[i];
            cout << sol(0, n) << endl;
          }
        }
        ```

## 快速排序法

- 切割：選定一個基準點 $x$ ，將其他數字分成兩堆， $< x$ 的數字排在 $x$ 前面， $\geq x$ 的數字排放在 $x$ 的後面，分堆完成，再分別遞迴排序兩堆。
- 終止條件：直到序列長度為 1，這時候已為一個排好的序列，直接回傳。
- 合併：已經排好順序，不需要額外的合併動作。

快速排序法是一種不穩定的演算法，最好時間複雜度為 $O(N\log N)$ ，最差時間複雜度為 $O(N^2)$ 。

## 二維平面上最近點對

給定二維平面上的 $N$ 個點，要找出距離最近的兩個點。

一開始先將點依 $x$ 座標排序。

- 切割：將點分成一半，分別遞迴。
- 終止條件：點數 $<3$ ，用兩層迴圈找出最近點對。
-   合併：
    - 設目前最小的點對距離為 $h$ 。
    - 左邊點集 $A_L$ ，右邊點集為 $A_R$ 。
    - 兩點集的中點為 $p_m(x_m,y_m)$ 。
    - 設點集 $B=\{p_i||x_i-x_m|< h\}$ 
    - 首先找出 $B$ ，因為要找到比 $h$ 找的點對會在 $B$ 裡，接著把 $B$ 裡的點對 $y$ 座標排序。接著將每個點和比自己的 $y$ 座標大的點取距離，如果有 $< h$ 就更新值，如果遇到跟自己的 $y$ 座標相差超過 $h$ 的點就停止比較（不可能距離會 $\leq h$ )。

合併的算法看似是 $O(N^2)$ ，但實際上只會列舉 $6$ 個點左右（這方面待證實正確個數，在此只要知道是一個很小的數），時間複雜度為 $O(N\log N)$ 。

```cpp
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
using dvt = double;
const dvt INF = 1e20;
const int MXN = 1e5 + 5;
struct dot {
  dvt x, y;
} p[MXN], tmp[MXN];

bool cmpX(dot a, dot b) { return a.x < b.x; }
bool cmpY(dot a, dot b) { return a.y < b.y; }

dvt getDis(dot a, dot b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

dvt nearestPair(int L, int R) {
  if (L == R) {
    return INF;
  }
  if (L + 1 == R) {
    return getDis(p[L], p[R]);
  }
  int M = (L + R) >> 1;
  dvt d = min(nearestPair(L, M), nearestPair(M, R));
  int k = 0;
  for (int i = L; i <= R; ++i) {
    if (fabs(p[i].x - p[M].x) <= d) {
      tmp[k++] = p[i];
    }
  }
  sort(tmp, tmp + k, cmpY);
  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k && tmp[j].y - tmp[i].y < d; ++j) {
      double d2 = getDis(tmp[i], tmp[j]);
      d = min(d, d2);
    }
  }
  return d;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  sort(p, p + n, cmpX);
  dvt res = nearestPair(0, n - 1);
  printf("%.2lf\n", res);
}
```

## 其他分治題目

???+ "UVA 1608：Non-boring sequences"
    給定一個序列 $A$ ，判斷使否每一個連續的子序列，都有一個數字，只在該子序列出現一次。
    ??? "解題思路"
        只要在序列 $[a_L,a_R]$ 中找到一個符合的數字 $A_i=x$ ，那麼所有在 $a_L$ 到 $a_R$ 之間，包含 $a_i$ 的連續子序列都符合，接著再判斷 $[a_L,i-1]$ 和 $[i+1,a_R]$ 兩個子序列是否符合即可。
        為了提升搜尋符合的數字，使用中途相遇法，從兩邊一起從中間找尋。
    ??? "參考程式碼"
        作者： [allem40306](https://github.com/allem40306) 
    
        ```cpp
        #include <iostream>
        #include <map>
        using namespace std;
        const int N = 200005;
        int a[N], L[N], R[N];

        bool sol(int a, int b)
        {
            if (a >= b)
                return 1;
            for (int i = 0; i <= (b - a) / 2; i++)
            {
                if (L[a + i] < a && b < R[a + i])
                {
                    return sol(a, a + i - 1) && sol(a + i + 1, b);
                }
                if (L[b - i] < a && b < R[b - i])
                {
                    return sol(a, b - i - 1) && sol(b - i + 1, b);
                }
            }
            return 0;
        }
        int main()
        {
            int t, n;
            map<int, int> tb;
            cin >> t;
            while (t--)
            {
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cin >> a[i];
                }
                tb.clear();
                for (int i = 0; i < n; i++)
                {
                    if (tb.find(a[i]) == tb.end())
                    {
                        L[i] = -1;
                    }
                    else
                    {
                        L[i] = tb[a[i]];
                    }
                    tb[a[i]] = i;
                }
                tb.clear();
                for (int i = n - 1; i >= 0; i--)
                {
                    if (tb.find(a[i]) == tb.end())
                    {
                        R[i] = n;
                    }
                    else
                    {
                        R[i] = tb[a[i]];
                    }
                    tb[a[i]] = i;
                }
                cout << (sol(0, n - 1) ? "non-boring\n" : "boring\n");
            }
        }
        ```

## 例題練習

-   合併排序法/逆序數對
    -  [UVa 10810 - Ultra-QuickSort](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1751) 
-   二維平面上最近點對
    -  [UVa 10245 - The Closest Pair Problem](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1186) 

[^1]:  [計算幾何 平面最近點對 nlogn 分治演算法 求平面中距離最近的兩點 in IT 閱讀](https://www.itread01.com/content/1544101384.html) 

[^2]:  [平面最近点对 in OI WiKi](https://oi-wiki.org/geometry/nearest-points/) 
