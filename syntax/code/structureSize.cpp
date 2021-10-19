struct Data1
{
    char ch1;
    int i;
    char ch2;
};

struct Data2
{
    char ch1;
    char ch2;
    int i;
};

int main()
{
    cout << sizeof(Data1) << '\n';
    cout << sizeof(Data2) << '\n';
}

/*
12
8
*/