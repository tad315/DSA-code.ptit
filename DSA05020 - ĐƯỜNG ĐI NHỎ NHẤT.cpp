#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int minPathSum(vector<vector<int>> &a, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = a[0][0];
    for (int j = 1; j < m; ++j)
        dp[0][j] = dp[0][j - 1] + a[0][j];

    for (int i = 1; i < n; ++i)
        dp[i][0] = dp[i - 1][0] + a[i][0];

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            dp[i][j] = a[i][j] + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    return dp[n - 1][m - 1];
}

int main()
{
    boost;
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        cout << minPathSum(a, n, m) << '\n';
    }

    return 0;
}
