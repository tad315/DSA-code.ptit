#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
#define ll long long

int solve(string &s)
{
    int open = 0, close = 0;
    for (char c : s)
    {
        if (c == '(')
            open++;
        else
        {
            if (open > 0)
                open--;
            else
                close++;
        }
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
