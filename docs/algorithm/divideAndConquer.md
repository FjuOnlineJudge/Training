# 分治
分治法會把問題分解成子問題(分)，解決完再合併回原本的問題(治)。\\
分治分成以下步驟
* 切割：把一個問題切成子問題然後遞迴
* 碰底：碰到不能再切割或是明顯有答案(也許無解)，就算出答案再回傳
* 合併：利用傳回來的子問題算出答案然後回傳
## 合併排序法
一個利用分治實作的排序法，逆序數對也會利用他的概念來實作。
* 切割：把序列分成兩半然後遞迴
* 碰底：直到序列長度為1，這時候已為一個排好的序列，直接回傳
* 合併：利用傳回來的兩串序列進行排序
```cpp
using namespace std;
const int N = 100;
int arr[N], buf[N];
void sol(int L, int R) { // [L,R)
	if (R - L <= 1)return;
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
	for (int k = L; k < R; k++) arr[k] = buf[k];
	return;
}
```