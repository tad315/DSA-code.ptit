#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
    boost;
    int t;
    ll p, q;
    cin >> t;
    while (t--)
    {
        cin >> p >> q;
        ll g = gcd(p, q);
        p /= g;
        q /= g;

        vector<ll> res;
        while (p != 1) {
            ll x = (q + p - 1) / p; 
            res.push_back(x);
            p = p * x - q;
            q = q * x;

            g = gcd(p, q);
            p /= g;
            q /= g;

            if (p == 0) break;
        }
        res.push_back(q);
        for (ll i = 0; i < res.size(); ++i) {
            if (i > 0) cout << " + ";
            cout << "1/" << res[i];
        }
        cout << endl;
    }
    return 0;
}
