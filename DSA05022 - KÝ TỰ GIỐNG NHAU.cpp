#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        int n, ins, del, cpy;
        cin >> n >> ins >> del >> cpy;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = ins;

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + ins;
            if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + cpy);
            else dp[i] = min(dp[i], dp[(i + 1) / 2] + cpy + del);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
