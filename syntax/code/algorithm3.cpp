int main()
{
    vector<int> a = {4, 6, 9, 3};
    for (int i = 0; i < 5; ++i)
    {
        if (find(a.begin(), a.end(), i) != a.end())
        {
            printf("%d is find at %d\n", i,
                   (int)(find(a.begin(), a.end(), i) - a.begin()));
        }
    }
    sort(a.begin(), a.end());
    printf("The lower_bound of %d is at %d\n", 5,
           (int)(lower_bound(a.begin(), a.end(), 5) - a.begin()));
    printf("The upper_bound of %d is at %d\n", 5,
           (int)(upper_bound(a.begin(), a.end(), 5) - a.begin()));
}

/*
3 is find at 3
4 is find at 0
The lower_bound of 5 is at 2
The upper_bound of 5 is at 2
*/