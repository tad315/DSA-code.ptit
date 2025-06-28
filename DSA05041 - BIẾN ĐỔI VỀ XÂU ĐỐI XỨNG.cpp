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

int solve(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
            {
                if (len == 2) dp[i][j] = 2;
                else dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return n - dp[0][n - 1];
}

int main()
{
    boost;
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        cout << solve(s) << endl;
    }
    return 0;
}
