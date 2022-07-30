int main()
{
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < k; ++i)
    {
        if ((int)s.size() == 0)
            break;
        int pos = (int)s.size() - 1;
        for (int j = 0; j < (int)s.size() - 1; ++j)
        {
            if (s[j] > s[j + 1])
            {
                pos = j;
                break;
            }
        }
        s.erase(pos, 1);
    }
    while ((int)s.size() > 0 && s[0] == '0')
        s.erase(0, 1);
    if ((int)s.size())
        cout << s << '\n';
    else
        cout << 0 << '\n';
}
