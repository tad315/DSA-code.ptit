#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

ll solve(vector<ll> &a, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return a[0];

    ll prev2 = a[0];
    ll prev1 = max(a[0], a[1]);

    for (int i = 2; i < n; ++i)
    {
        ll cur = max(prev1, prev2 + a[i]);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout << solve(a, n) << endl;
    }
    return 0;
}
