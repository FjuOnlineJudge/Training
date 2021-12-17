int total = 0;
vector<int> v = {5, 2, 4, 1, 3};

// sort elements descendingly
sort(s.begin(), s.end(), [](int a, int b) {return a > b;});

// accumulate elements
for_each(v.begin(), v.end(),[&total](int x) {total += x;});

for(auto i: v)cout << v[i] << '\n';
cout << total << '\n';