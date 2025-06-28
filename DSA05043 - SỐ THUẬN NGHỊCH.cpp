#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int solve(string &s)
{
    int n = s.length();
    int maxLen = 1;
    for (int i = 0; i < n; ++i)
    {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            maxLen = max(maxLen, r - l + 1);
            --l;
            ++r;
        }
        l = i; 
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            maxLen = max(maxLen, r - l + 1);
            --l;
            ++r;
        }
    }
    return maxLen;
}

int main()
{
    boost;
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        cout << solve(s) << endl;
    }
    return 0;
}
