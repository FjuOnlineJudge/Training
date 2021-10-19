int cmp(int a, int b) { return a > b; }

int main()
{
    int arr[5] = {2, 9, 6, 5, 7};
    printf("Before sorting:\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort(arr, arr + 5);
    printf("After sorting:\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort(arr, arr + 5, cmp);
    printf("After sorting with user-defined function:\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
Before sorting:
2 9 6 5 7
After sorting:
2 5 6 7 9
After sorting with user-defined function:
9 7 6 5 2
*/