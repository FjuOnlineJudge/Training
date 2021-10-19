int arr[5];
printf("Before memeset:\n");
for (int i = 0; i < 5; ++i)
{
    printf("%d ", arr[i]);
}
memset(arr, -1, sizeof(arr));
printf("\nAfter memeset:\n");
for (int i = 0; i < 5; ++i)
{
    printf("%d ", arr[i]);
}

/*
Before memeset:
8 0 2 0 7480496
After memeset:
-1 -1 -1 -1 -1
*/