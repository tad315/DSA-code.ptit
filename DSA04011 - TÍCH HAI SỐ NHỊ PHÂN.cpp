#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
#define ll long long

ll bin(const string&s){
    ll res = 0;
    for (char c:s){
        res = (res<<1) + (c-'0');
    }
    return res;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << bin(s1) * bin(s2) << endl;
    }
    return 0;
}
