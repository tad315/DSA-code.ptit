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
const ll INF = -1e18;

int main()
{
    boost;
    int t;
    cin >> t;
    ll dp[10005][20] = {};
    while (t--)
    {
        int n;
        cin >> n;

        ll a[4][n + 5];
        ll Max = INF;

        for (int r = 0; r < 4; ++r)
        {
            for (int c = 1; c <= n; ++c)
            {
                cin >> a[r][c];
                Max = max(Max, a[r][c]);
            }
        }

        if (Max <= 0)
        {
            cout << Max << endl;
            continue;
        }

        bitset<20> mask;
        for (int i = 0; i < 16; ++i)
        {
            bool isVal = 1;
            for (int r = 0; r < 3; ++r)
            {
                if (((i >> r) & 1) && ((i >> (r + 1)) & 1))
                {
                    isVal = 0;
                    break;
                }
            }
            mask[i] = isVal;
        }
        ll res = INF;
        for (int c = 1; c <= n; ++c)
        {
            for (int i = 0; i < 16; ++i)
            {
                dp[c][i] = INF;
                if (mask[i])
                {
                    int totalCol = 0;
                    for (int r = 0; r < 4; ++r)
                        if ((i >> r) & 1)
                            totalCol += a[r][c];
                            
                    for (int j = 0; j < 16; ++j)
                        if (mask[j] && (i & j) == 0)
                            dp[c][i] = max(dp[c][i], dp[c - 1][j] + totalCol);
                }
                res = max(res, dp[c][i]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
