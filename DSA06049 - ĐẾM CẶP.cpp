#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define endl '\n'
#define ll long long

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll ans = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            ans += lower_bound(a.begin() + i + 1, a.end(), k + a[i]) - (a.begin() + i + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
