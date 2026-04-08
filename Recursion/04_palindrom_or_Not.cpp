#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int palindrom(string &s, int l, int r)
{
    if (l >= r)
        return true;
    if (s[l] != s[r])
        return 0;
    palindrom(s, l + 1, r - 1);
}

int main()
{
    string s = "malayalam";
    int l = 0, r = s.length() - 1;
    cout << palindrom(s, l, r);
    return 0;
}