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

int main()
{
    boost;
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a[n + 5];
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> dp(k, -1);
        for (int i = 0; i < n; ++i)
        {
            vector<int> ndp(dp);
            for (int j = 0; j < k; ++j)
            {
                if (dp[j] != -1)
                {
                    int idx = (j + a[i]) % k;
                    ndp[idx] = max(ndp[idx], dp[j] + 1);
                }
            }
            ndp[a[i] % k] = max(ndp[a[i] % k], 1);
            dp = ndp;
        }
        cout << dp[0] << endl;
    }
    return 0;
}
