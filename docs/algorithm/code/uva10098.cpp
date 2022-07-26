sort(s.begin(), s.end());
do{
    cout << s << endl;
} while (next_permutation(s.begin(), s.end(), comp));