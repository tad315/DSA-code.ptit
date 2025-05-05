#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        ll res = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<ll>());
        for (int i = 0; i < n; ++i)
            res += a[i] * b[i];
        cout << res << endl;        
    }
    return 0;
}
