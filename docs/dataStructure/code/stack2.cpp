#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(1);
    cout << st.top() << '\n';
    st.push(2);
    cout << st.top() << '\n';
    st.push(3);
    cout << st.top() << '\n';
    st.pop();
    cout << st.top() << '\n';
}

/*
1
2
3
2
*/