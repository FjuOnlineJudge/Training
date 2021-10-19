#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> tb;
    tb["123"] = 1;
    tb["owowowo"] = 2;
    tb["omomo"] = 3;
    cout << "tb[\"123\"]: " << tb["123"] << '\n';
    cout << "tb[\"owowowo\"]: " << tb["owowowo"] << '\n';
    cout << "tb[\"omomo\"]: " << tb["omomo"] << '\n';

    cout << "123 : " << (tb.find("123") != tb.end() ? "find\n" : "not find\n");
    cout << "123 : " << (tb.count("123") ? "find\n" : "not find\n");

    tb.clear();
    cout << "123 : " << (tb.find("123") != tb.end() ? "find\n" : "not find\n");
    cout << "123 : " << (tb.count("123") ? "find\n" : "not find\n");

    cout << "owo : " << (tb.find("owo") != tb.end() ? "find\n" : "not find\n");
    tb.insert(make_pair("owo", 659));
    cout << "owo : " << (tb.find("owo") != tb.end() ? "find\n" : "not find\n");
}

/*
tb["123"]: 1
tb["owowowo"]: 2
tb["omomo"]: 3
123 : find
123 : find
123 : not find
123 : not find
owo : not find
owo : find
*/