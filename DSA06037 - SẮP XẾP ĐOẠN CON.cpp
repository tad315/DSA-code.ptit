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
        vector<ll> a(n + 2), maxL(n + 2), minR(n + 2);

        for (int i = 1; i <= n; ++i) cin >> a[i];

        maxL[0] = LLONG_MIN;
        for (int i = 1; i <= n; ++i)
            maxL[i] = max(maxL[i - 1], a[i]);

        minR[n + 1] = LLONG_MAX;
        for (int i = n; i >= 1; --i)
            minR[i] = min(minR[i + 1], a[i]);

        vector<int> ans;
        for (int m = 1; m < n; ++m)
            if (maxL[m] <= minR[m + 1]) ans.push_back(m);

        cout << ans.size() << endl;
        for (int x : ans) cout << x << ' ';
        if (!ans.empty()) cout << endl;
    }
    return 0;
}
