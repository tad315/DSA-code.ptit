#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort (a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            auto it = upper_bound(a.begin() + i + 1, a.end(), a[i] + k - 1);
            ans += it - (a.begin() + i + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
