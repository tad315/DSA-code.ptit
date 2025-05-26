#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int solve(string s)
{
    int n = s.size(), maxLen = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    for (int i = 0; i < n - 1; ++i)
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            maxLen = 2;
        }

    for (int len = 3; len <= n; ++len)
    {
        for (int i = 0; i + len - 1 < n; ++i)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                maxLen = len;
            }
        }
    }

    return maxLen;
}

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
