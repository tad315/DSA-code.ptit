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
        int n, v;
        cin >> n >> v;
        vector<int> a(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        vector<int> dp(v + 1, 0);

        for (int i = 0; i < n; i++)
            for (int j = v; j >= a[i]; j--)
                dp[j] = max(dp[j], dp[j - a[i]] + c[i]);

        cout << dp[v] << endl;
    }
    return 0;
}
