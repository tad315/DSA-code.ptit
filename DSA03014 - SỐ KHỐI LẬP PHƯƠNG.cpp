#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

bool isCube (ll x)
{
    ll root = round(cbrt(x));
    return root * root * root == x;
}

void solve(string s)
{
    int n = s.size();
    ll maxCube = -1;
    for (int mask = 1; mask < (1 << n); ++mask)
    {
        string tmp = "";
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i)) tmp += s[i];
        }
        if (tmp[0] == '0') continue;
        ll num = stoll(tmp);
        if (isCube(num)) maxCube = max(maxCube, num);
    }
    cout << maxCube << endl;    
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
