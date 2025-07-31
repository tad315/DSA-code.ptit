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
const ll mod = 1e9 + 7;

ll revN (ll n)
{
    ll tmp = 0; 
    while (n)
    {
        tmp = tmp * 10 + n % 10;
        n /= 10;
    }
    return tmp;
}

ll calc(ll n, ll k)
{
    if (k == 0) return 1;
    ll res = calc(n, k / 2);
    res = (res * res) % mod;
    if (k % 2 == 0) return res;
    else return (res * n) % mod;
}
int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << calc(n, revN(n)) << endl;
    }
    return 0;
}
