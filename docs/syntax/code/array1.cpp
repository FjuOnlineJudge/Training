const int SIZE = 100;
int num;
int arr1[100];            // OK
int arr2[SIZE];           // OK
int arr3[num];            // 錯誤，不可使用變數設定大小。
int arr4[10] = {1, 2, 3}; // 使用 initializer_list。
arr1 = {1, 2, 3}; // 錯誤，只可在宣告時使用 initializer_list。