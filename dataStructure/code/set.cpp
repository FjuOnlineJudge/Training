#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> sb;
    sb.insert(1);
    sb.insert(2);
    sb.insert(3);

    cout << "1 : " << (sb.find(1) != sb.end() ? "find\n" : "not find\n");
    cout << "1 : " << (sb.count(1) ? "find\n" : "not find\n");

    sb.erase(1);
    cout << "1 : " << (sb.find(1) != sb.end() ? "find\n" : "not find\n");
    cout << "1 : " << (sb.count(1) ? "find\n" : "not find\n");
}

/*
1 : find
1 : find
1 : not find
1 : not find
*/