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
    int t;
    cin >> t;
    while (t--)
    {
        string n, m;
        cin >> n >> m;
        int a = n.size(), b = m.size();
        vector<vector<int>> dp(2, vector<int>(b + 1, 0));
        for (int i = 1; i <= a; ++i)
        {
            int cur = i % 2, pre = 1 - cur;
            for (int j = 1; j <= b; ++j)
            {
                if (n[i - 1] == m[j - 1])
                    dp[cur][j] = dp[pre][j - 1] + 1;
                else
                    dp[cur][j] = max(dp[pre][j], dp[cur][j - 1]);
            }
        }
        cout << dp[a % 2][b] << endl;
    }
    return 0;
}
