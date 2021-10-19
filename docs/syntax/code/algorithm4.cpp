int main()
{
    vector<int> a1 = {4, 2, 7, 5};
    vector<int> a2(a1);
    if (next_permutation(a1.begin(), a1.end()))
    {
        for (int i = 0; i < (int)a1.size(); ++i)
        {
            printf("%d%c", a1[i], " \n"[i == (int)a1.size() - 1]);
        }
    }
    if (prev_permutation(a2.begin(), a2.end()))
    {
        for (int i = 0; i < (int)a2.size(); ++i)
        {
            printf("%d%c", a2[i], " \n"[i == (int)a2.size() - 1]);
        }
    }
}

/*
4 5 2 7
4 2 5 7
*/