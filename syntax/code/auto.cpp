auto i; // error
auto j = 1;
auto f(){return 1;} // from C++14

vector<int> v={1,2,3,4,5};

for(auto it = v.begin(); it != v.end(); ++it)
    cout << *it << '\n';

for(auto x: v)
    cout << x << '\n';