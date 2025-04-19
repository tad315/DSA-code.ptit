#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (n == 1)
        {
            cout << a[0] << endl;
            continue;
        }

        ll pre2 = a[0], pre1 = max(a[0], a[1]);
        for (int i = 2; i < n; i++)
        {
            ll cur = max(pre2 + a[i], pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        cout << pre1 << endl;
    }
    return 0;
}
