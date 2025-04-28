#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        string gray = "";
        gray += s[0];
        for (int i = 1; i < s.size(); ++i)
            gray += (s[i] == s[i - 1]) ? '0' : '1';
        cout << gray << endl;
    }
    return 0;
}
