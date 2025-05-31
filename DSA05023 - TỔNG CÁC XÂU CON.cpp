#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const ll MOD = 1e9 + 7;

ll calc (string &s)
{
    ll res = 0, prev = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        int tmp = s[i] - '0';
        ll cur = prev * 10 + (ll)(i + 1) * tmp;
        res += cur;
        prev = cur;
    }
    return res;
}

int main()
{
    boost;
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        cout << calc(s) << endl;
    }
    return 0;
}


