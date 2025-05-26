#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int dp[105][105][105];

int lcs3(string &x, string &y, string &z)
{
    int n = x.size(), m = y.size(), p = z.size();
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k <= p; ++k)
            {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (x[i - 1] == y[j - 1] && y[j - 1] == z[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
    return dp[n][m][p];
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        string x, y, z;
        cin >> x >> y >> z;
        cout << lcs3(x, y, z) << '\n';
    }
    return 0;
}
