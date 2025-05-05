#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
const int mod = 1e9 + 7;
int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; ++i)
        {
            ll x;
            cin >> x;
            pq.push(x);
        }

        ll res = 0, a, b;
        while (pq.size() > 1)
        {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();
            ll sum = (a + b) % mod;
            res = (res + sum) % mod;
            pq.push(sum);
        }
        cout << res << endl;
    }
    return 0;
}
