#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define MOD 1000000007

int minSquares(int n)
{
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j * j <= i; ++j)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}

int main()
{
    boost;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << minSquares(n) << '\n';
    }
    return 0;
}
