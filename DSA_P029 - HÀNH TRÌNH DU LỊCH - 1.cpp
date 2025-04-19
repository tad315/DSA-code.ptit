#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

const int INF = 1e9;
int dp[1 << 15][15];

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];

        int full = 1 << n;
        for (int mask = 0; mask < full; mask++)
            for (int i = 0; i < n; i++)
                dp[mask][i] = INF;

        for (int i = 0; i < n; i++)
            dp[1 << i][i] = 0;

        for (int mask = 0; mask < full; mask++)
        {
            for (int u = 0; u < n; u++)
            {
                if (!(mask & (1 << u))) continue;
                for (int v = 0; v < n; v++)
                {
                    if (mask & (1 << v)) continue;
                    int next = mask | (1 << v);
                    dp[next][v] = min(dp[next][v], dp[mask][u] + cost[u][v]);
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < n; i++)
            ans = min(ans, dp[full - 1][i]);
        cout << ans << endl;
    }
    return 0;
}
