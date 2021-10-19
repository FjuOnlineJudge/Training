int main()
{
    printf("Min(1,2): %d\n", min(1, 2));
    printf("max(1,2): %d\n", max(1, 2));
    printf("Min({2,7,5}): %d\n", min({2, 7, 5}));
    printf("max({2,7,5}): %d\n", max({2, 7, 5}));
    vector<int> a = {4, 6, 9, 3};
    printf("Min_element(a): %d\n", *min_element(a.begin(), a.end()));
    printf("max_element(a): %d\n", *max_element(a.begin(), a.end()));
}

/*
Min(1,2): 1
max(1,2): 2
Min({2,7,5}): 2
max({2,7,5}): 7
Min_element(a): 3
max_element(a): 9
*/