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
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
            {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        cout << dp[n][m] << endl;
    }
    return 0;
}
