#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> Q;
    Q.push(2);
    cout << Q.top() << '\n';
    Q.push(5);
    cout << Q.top() << '\n';
    Q.pop();
    cout << Q.top() << '\n';
    Q.push(3);
    cout << Q.top() << '\n';
}

/*
2
5
2
3
*/