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

ll start(ll x, ll y)
{
    ll sum = 1LL + x * (x - 1) / 2;
    sum += ((2 * x + y) * (y - 1)) / 2;
    return sum;
}

int main()
{
    boost;
    ll x, y , z;
    cin >> x >> y >> z;
    cout << start(x, y) << endl;
    ll row = 1;
    while (1)
    {
        ll l = 1, r = 2e6, ans = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll val = start(row, mid);
            if (val == z)
            {
                ans = mid;
                break;
            }
            else if (val < z) l = mid + 1;
            else r = mid - 1;
        }
        if (ans != -1)
        {
            cout << row << " " << ans << endl;
            break;
        }
        if (start(row, 1) > z) break;
        ++row;
    }
    return 0;
}
