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
const int mod = 1e9 + 7;
const int MAXK = 50000;

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i].first >> v[i].second;
        sort(all(v));
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (v[j].second < v[i].first)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}
