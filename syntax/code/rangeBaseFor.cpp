vector<int> v={1,2,3,4,5};

for(int i = 0; i < (int)v.size();++v)
    cout << v[i] << '\n';

for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << *it << '\n';

for(int x: v)
    cout << x << '\n';

for(int &x: v)
    ++x;

for(int x: v)
    cout << x << '\n';